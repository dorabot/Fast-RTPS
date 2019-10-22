/*
 * Copyright 2019, Proyectos y Sistemas de Mantenimiento SL (eProsima).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef EPROSIMA_DDS_PUB_DATA_WRITER_IMPL_HPP_
#define EPROSIMA_DDS_PUB_DATA_WRITER_IMPL_HPP_

/***************************************************************************
 *
 * dds/pub/DataWriter<> WRAPPER implementation.
 * Declaration can be found in dds/pub/DataWriter.hpp
 *
 ***************************************************************************/

//#include <dds/topic/Topic.hpp>
#include <dds/pub/DataWriter.hpp>
#include <dds/pub/DataWriterListener.hpp>

namespace dds {
namespace pub {

// TODO Uncomment when PSM DDS Topic is ready to be used
//template<typename T>
//DataWriter<T>::DataWriter(
//        const dds::pub::Publisher& pub,
//        const dds::topic::Topic<T>& topic)
//    : dds::core::Reference<detail::DataWriter<T>>(
//            new detail::DataWriter<T>(pub,
//                            topic,
//                            pub.is_nil() ? dds::pub::qos::DataWriterQos() : pub.default_datawriter_qos(),
//                            NULL,
//                            dds::core::status::StatusMask::none()))
//{
//}

// TODO Uncomment when PSM DDS Topic is ready to be used
//template<typename T>
//DataWriter<T>::DataWriter(
//        const dds::pub::Publisher& pub,
//        const ::dds::topic::Topic<T>& topic,
//        const dds::pub::qos::DataWriterQos& qos,
//        dds::pub::DataWriterListener<T>* listener,
//        const dds::core::status::StatusMask& mask)
//    : dds::core::Reference<detail::DataWriter<T>>(
//            new detail::DataWriter<T>(pub, topic, qos, listener, mask))
//{
//}

template<typename T>
DataWriter<T>::~DataWriter()
{
}

template<typename T>
void DataWriter<T>::write(
        const T& sample)
{
    delegate()->write(sample);
}

template<typename T>
void DataWriter<T>::write(
        const T& sample,
        const dds::core::Time& timestamp)
{
    delegate()->write(sample, timestamp);
}

template<typename T>
void DataWriter<T>::write(
        const T& sample,
        const ::dds::core::InstanceHandle& instance)
{
    delegate()->write(sample, instance);
}

template<typename T>
void DataWriter<T>::write(
        const T& sample,
        const ::dds::core::InstanceHandle& instance,
        const dds::core::Time& timestamp)
{
    delegate()->write(sample, instance, timestamp);
}

// TODO Uncomment when PSM DDS Topic is ready to be used
//template<typename T>
//void DataWriter<T>::write(
//        const dds::topic::TopicInstance<T>& i)
//{
//    delegate()->write(i);
//}

// TODO Uncomment when PSM DDS Topic is ready to be used
//template<typename T>
//void DataWriter<T>::write(
//        const dds::topic::TopicInstance<T>& i,
//        const dds::core::Time& timestamp)
//{
//    delegate()->write(i, timestamp);
//}

template<typename T>
template<typename FWIterator>
void DataWriter<T>::write(
        const FWIterator& begin,
        const FWIterator& end)
{
    //To implement
//    ISOCPP_REPORT_STACK_DDS_BEGIN(*this);

//    FWIterator b = begin;
//    while(b != end)
//    {
//        this->delegate()->write(*b);
//        ++b;
//    }
}

template<typename T>
template<typename FWIterator>
void DataWriter<T>::write(
        const FWIterator& begin,
        const FWIterator& end,
        const dds::core::Time& timestamp)
{
    //To implement
//    ISOCPP_REPORT_STACK_DDS_BEGIN(*this);

//    FWIterator b = begin;
//    while(b != end)
//    {
//        this->delegate()->write(*b, timestamp);
//        ++b;
//    }
}

template<typename T>
template<
        typename SamplesFWIterator,
        typename HandlesFWIterator>
void DataWriter<T>::write(
        const SamplesFWIterator& data_begin,
        const SamplesFWIterator& data_end,
        const HandlesFWIterator& handle_begin,
        const HandlesFWIterator& handle_end)
{
    //To implement
//    ISOCPP_REPORT_STACK_DDS_BEGIN(*this);

//    SamplesFWIterator data = data_begin;
//    HandlesFWIterator handle = handle_begin;

//    while(data != data_end && handle != handle_end)
//    {
//        this->delegate()->write(*data, *handle);
//        ++data;
//        ++handle;
//    }
}

template<typename T>
template<
        typename SamplesFWIterator,
        typename HandlesFWIterator>
void DataWriter<T>::write(
        const SamplesFWIterator& data_begin,
        const SamplesFWIterator& data_end,
        const HandlesFWIterator& handle_begin,
        const HandlesFWIterator& handle_end,
        const dds::core::Time& timestamp)
{
    //To implement
//    ISOCPP_REPORT_STACK_DDS_BEGIN(*this);

//    SamplesFWIterator data = data_begin;
//    HandlesFWIterator handle = handle_begin;

//    while(data != data_end && handle != handle_end)
//    {
//        this->delegate()->write(*data, *handle, timestamp);
//        ++data;
//        ++handle;
//    }
}

template<typename T>
DataWriter<T>& DataWriter<T>::operator <<(
        const ::dds::pub::qos::DataWriterQos& qos)
{

    this->qos(qos);
    return *this;
}

template<typename T>
DataWriter<T>& DataWriter<T>::operator <<(
        const T& data)
{
    this->write(data);
    return *this;
}

template<typename T>
DataWriter<T>& DataWriter<T>::operator <<(
        const std::pair<T, dds::core::Time>& data)
{
    this->write(data.first, data.second);
    return *this;
}

template<typename T>
DataWriter<T>& DataWriter<T>::operator <<(
        const std::pair<T, ::dds::core::InstanceHandle>& data)
{
    this->write(data.first, data.second);
    return *this;
}

template<typename T>
DataWriter<T>& DataWriter<T>::operator <<(
        DataWriter & (*manipulator)(DataWriter&))
{
    return manipulator(*this);
}

template<typename T>
const dds::core::InstanceHandle DataWriter<T>::register_instance(
        const T& key)
{
    //TODO Implement register_instance in fastdds DataWriter
    //return this->delegate()->register_instance(key, dds::core::Time::invalid());
    (void) key;
    return *this;
}

template<typename T>
const dds::core::InstanceHandle DataWriter<T>::register_instance(
        const T& key,
        const dds::core::Time& timestamp)
{
    //TODO Implement register_instance in fastdds DataWriter
    //return this->delegate()->register_instance(key, timestamp);
    (void) key;
    (void) timestamp;
    return *this;
}

template<typename T>
DataWriter<T>& DataWriter<T>::unregister_instance(
        const ::dds::core::InstanceHandle& i)
{
    //TODO Implement unregister_instance in fastdds DataWriter
    //this->delegate()->unregister_instance(i, dds::core::Time::invalid());
    (void) i;
    return *this;
}

template<typename T>
DataWriter<T>& DataWriter<T>::unregister_instance(
        const ::dds::core::InstanceHandle& i,
        const dds::core::Time& timestamp)
{
    //TODO Implement unregister_instance in fastdds DataWriter
    //this->delegate()->unregister_instance(i, timestamp);
    (void) i;
    (void) timestamp;
    return *this;
}

template<typename T>
DataWriter<T>& DataWriter<T>::unregister_instance(
        const T& key)
{
    //TODO Implement unregister_instance in fastdds DataWriter
    //this->delegate()->unregister_instance(key, dds::core::Time::invalid());
    (void) key;
    return *this;
}

template<typename T>
DataWriter<T>& DataWriter<T>::unregister_instance(
        const T& key,
        const dds::core::Time& timestamp)
{
    //TODO Implement unregister_instance in fastdds DataWriter
    //this->delegate()->unregister_instance(key, timestamp);
    (void) key;
    (void) timestamp;
    return *this;
}

template<typename T>
DataWriter<T>& DataWriter<T>::dispose_instance(
        const ::dds::core::InstanceHandle& i)
{
    //TODO Implement dispose_instance in fastdds DataWriter
    //this->delegate()->dispose_instance(i, dds::core::Time::invalid());
    (void) i;
    return *this;
}

template<typename T>
DataWriter<T>& DataWriter<T>::dispose_instance(
        const ::dds::core::InstanceHandle& i,
        const dds::core::Time& timestamp)
{
    //TODO Implement dispose_instance in fastdds DataWriter
    //this->delegate()->dispose_instance(i, timestamp);
    (void) i;
    (void) timestamp;
    return *this;
}

template<typename T>
DataWriter<T>& DataWriter<T>::dispose_instance(
        const T& key)
{
    //TODO Implement dispose_instance in fastdds DataWriter
    //this->delegate()->dispose_instance(key, dds::core::Time::invalid());
    (void) key;
    return *this;
}

template<typename T>
DataWriter<T>& DataWriter<T>::dispose_instance(
        const T& key,
        const dds::core::Time& timestamp)
{
    //TODO Implement dispose_instance in fastdds DataWriter
    //this->delegate()->dispose_instance(key, timestamp);
    (void) key;
    (void) timestamp;
    return *this;
}

// TODO Uncomment when PSM DDS Topic is ready to be used
//template<typename T>
//dds::topic::TopicInstance<T>& DataWriter<T>::key_value(
//        dds::topic::TopicInstance<T>& i,
//        const ::dds::core::InstanceHandle& h)
//{
//    return this->delegate()->key_value(i, h);
//}

template<typename T>
T& DataWriter<T>::key_value(
        T& sample,
        const ::dds::core::InstanceHandle& h)
{
    //TODO Implement get_key_value in fastdds DataWriter
    //return delegate()->get_key_value(sample, h);
    (void) sample;
    (void) h;
    return *this;
}

template<typename T>
dds::core::InstanceHandle DataWriter<T>::lookup_instance(
        const T& key)
{
    //TODO Implement lookup_instance in fastdds DataWriter
    //return this->delegate()->lookup_instance(key);
    (void) key;
    return *this;
}

// TODO Uncomment when PSM DDS Topic is ready to be used
//template<typename T>
//const dds::topic::Topic<T>& DataWriter<T>::topic() const
//{
//    return this->delegate()->topic();
//}

template<typename T>
void DataWriter<T>::listener(
        DataWriterListener<T>* listener,
        const ::dds::core::status::StatusMask& mask)
{
    //TODO Adapt set_listener in fastdds to use mask
    //delegate()->set_listener(listener, mask);
}

template<typename T>
DataWriterListener<T>* DataWriter<T>::listener() const
{
    return delegate()->get_listener();
}

} //namespace dds
} //namespace pub

/** @endcond */

#endif //EPROSIMA_DDS_PUB_DATA_WRITER_IMPL_HPP_
