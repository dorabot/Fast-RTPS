# xtypes
Lightweight C++ implementation of dds-xtypes.

## Getting Started
Given the following IDL:

```c++
struct Inner {
    long a;
};

struct Outter {
    long b;
    Inner c;
};
```

You can create the representative code that define these IDL types using xtypes:

```c++
StructType inner("Inner");
outter.add_member("a", primitive_type<int>());

StructType outter("Outter");
outter.add_member("b", inner);
outter.add_member("c", primitive_type<int>());
```

Once you defined the types, you can instatiate them and access to their data easily:
```c++
DynamicData data(outter);
//write value
data["b"]["a"].value(42);

// read value
int my_value = data["b"]["a"].value<int>();
```

## Why use *eProsima xtypes*?
- **OMG standard**: eProsima xtypes is based on the [dds-xtypes standard](https://www.omg.org/spec/DDS-XTypes/About-DDS-XTypes/) from the omg.
- **C++11 API**: it uses most modern features of C++11 to offer a really easy API to use.
- **Memory lightweight**: data instantiations use the same memory as types builts by the compiler.
There is no memory penalty using eProsima xtypes in realtion to compiled types.
- **Fast**: really small cost accesing to data members.
- **Header only library**: avoid the linking problems.
- **No external dependency**: eProsima xtypes only uses tools from std.
- **Easy to use**: Compresive API and intuitive concepts.

## API usage
*Examples can be found in [example folder](../examples/ModernC++/xtypes folder).*

### Type definition
All types inherit from DynamicType as the following diagram represents:

// image

#### PrimitiveType
Represents the basic type of the system.
For creating a `PrimitiveType`, a helper function must be used:
```c++
const DynamicType& t = primitive_type<T>();
```
where `T` can be one of the following basic types:
`char` `uint8_t` `int16_t` `uint16_t` `int32_t` `uint32_t` `int64_t` `uint64_t` `float` `double` `char32`

#### Collection Type
There are several collection types:

- `ArrayType`: for a fixed size arrange of elements. Similar to *C* arrays.
- `SequenceType`: for a variable size arrange of elements. Equivalent to `std::vector` in *C++*
- `StringType`: for a variable size arrange of chars. Similar to `std::string` in *C++*

```c++
ArrayType a1(primitive_type<int>(), 10); //size 10
ArrayType a2(struct, 10); //Array of structs (struct previously defined as StructType)
SequenceType s1(primitive<float>()); //unbounded sequence
SequenceType s2(primitive<float>(),30); //bounded sequence, max size will be 30
SequenceType s3(SequenceType(struct), 20); //bounded sequence of unbounded sequences of structs.
StringType str1; //unbounded string
StringType str2(50); //bounded string
```

#### StructType
You can specify an `StructType` givin a type name for this structure.
```c++
StructType my_struct("MyStruct");
```
Similar to a *C struct*, `StructType` represents an aggregation of members.
Once it has been declared, any number of members can be added.
```c++
my_struct.add_member(Member("m_a", primitive_type<int>()));
my_struct.add_member(Member("m_b", StringType()));
my_struct.add_member(Member("m_c", primitive_type<double>().optional().id(42))); //with annotations
my_struct.add_member("m_d", ArrayType(25)); //shortcut version
my_struct.add_member("m_e", other_struct)); //member of structs
my_struct.add_member("m_f", SequenceType(other_struct))); //member of sequence of structs
```
Note: once a `DynamicType` is added to an struct, a copy is performed (excepts for PrimitiveType).
This allow to modify the `DynamicType`s without side effects, and facilitate the memory management of the
DynamicType by the user.

##### Struct Member annotations
There are several member annotations:
- optional(): Set the member as optional.
- id(value): Set the id to the member.
- key(): Set the member as key member.

#### `is_convertible_from` function of DynamicType
//TODO
Any DynamicType can be tested with another DynamicType in a *subset* evaluation.
Given the following line:
```c++
t1.is_convertible_from(t2)
```
The previous sentence will be evaluate true if it is possible to get a instance of `t1` that be compatible with an instance of `t2`.

### Data instantation
In order to instantiate a data from a DynamicType, only is necessary to call the DynamicData constructor:
```c++
DynamicData data(my_defined_type);
```
This line allocates all the memory necesary to hold the data of `my_defined_type`.
It is important to know that the type must have a higher lifetime than the DynamicData,
because the DynamicData only save a references to it.

Depends of the type, the data will be behave in different ways.
The following methods are available to use when:
1. `DynamicData` represents a PrimitiveType (of `int` as example):
  ```c++
  data.value(42); //sets the value to 42
  int value = data.value<int>(); //read the value
  ```
2. `DynamicData` represents a StringType
  ```c++
  data.value<std::string>("Hello data!"); //sets the string value
  data.string("Hello again!"); // shortcut version for string
  const std::string& s1 = data.value<std::string>(); //read the string value
  const std::string& s2 = data.string(); // shortcut version for string
  ```
3. `DynamicData` represents a CollectionType
  ```c++
  size_t size = data.size(); //size of collection
  data[2].value(42); // set value 42 to position 2 of the collection.
  int value = data[2].value<int>(); // get value from position 2 of the collection.
  data[2] = dynamic_data_representing_a_value;
  WritableDynamicDataRef ref = data[2]; //references to a DynamicData that represents a collection
  ```
4. `DynamicData` represents a SequenceType
  ```c++
  data.push(42); // push back new value to the sequence.
  data.push(dynamic_data_representing_a_value);
  ```
5. `DynamicData` represents an AggregationType
  ```c++
  data["member_name"].value(42); //set value 42 to the int member called "member_name"
  int value = data["member_name"].value<int>(); //get value from int member called "member_name"
  data["member_name"].value(dynamic_data_representing_a_value);
  WritableDynamicDataRef ref = data["member_name"];
  ```

#### References to `DynamicData`
There are two ways to obtain a references to a `DynamicData`:
1. `ReadableDynamicDataRef` for `const` references.
2. `WritableDynamicDataRef` for mutable references.

A reference no contain any value, only points to an already existing `DynamicData` part of it.
You can get a reference when access with the `[]` operator or calling the `ref()` or `cref()` of a `DynamicData`.
If you will obtain a `ReadableDynamicDataRef` or a `WritableDynamicDataRef` depending if the theses operators are
calling from a `const DynamicData` or from a `DynamicData` itself.

#### `operator ==` of DynamicData

#### `for_each` function of DynamicData


## Performance
