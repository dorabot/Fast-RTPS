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

#ifndef EPROSIMA_DDS_SUB_DATAREADER_IMPL_HPP_
#define EPROSIMA_DDS_SUB_DATAREADER_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/sub/DataReader.hpp>
#include <dds/sub/Query.hpp>
#include <dds/sub/detail/SamplesHolder.hpp>

/***************************************************************************
 *
 * dds/sub/DataReader<> WRAPPER implementation.
 * Declaration can be found in dds/sub/DataReader.hpp
 *
 ***************************************************************************/

// Implementation

namespace dds {
namespace sub {

//--------------------------------------------------------------------------------
//  DATAREADER
//--------------------------------------------------------------------------------

template<typename T>
DataReader<T>::Selector::Selector(
        DataReader<T>& dr)
    : impl_(dr.delegate())
{
}

template<typename T>
typename DataReader<T>::Selector& DataReader<T>::Selector::instance(
        const dds::core::InstanceHandle& h)
{
    //TODO Implement set_instance in fastdds DataWriter
//    impl_.instance(h);
    return *this;
}


template<typename T>
typename DataReader<T>::Selector& DataReader<T>::Selector::next_instance(
        const dds::core::InstanceHandle& h)
{
    //TODO Implement next_instance in fastdds DataWriter
//    impl_.next_instance(h);
    return *this;
}


template<typename T>
typename DataReader<T>::Selector& DataReader<T>::Selector::state(
        const dds::sub::status::DataState& s)
{
    //TODO Implement filter_by_state in fastdds DataWriter
//    impl_.filter_state(s);
    return *this;
}

template<typename T>
typename DataReader<T>::Selector& DataReader<T>::Selector::content(
        const dds::sub::Query& query)
{
    //TODO Implement filter_by_content in fastdds DataWriter
//    impl_.filter_content(query);
    return *this;
}

template<typename T>
typename DataReader<T>::Selector& DataReader<T>::Selector::max_samples(
        uint32_t n)
{
    //TODO Implement set_max_samples in fastdds DataWriter
//    impl_.max_samples(n);
    return *this;
}

template<typename T>
dds::sub::LoanedSamples<T> DataReader<T>::Selector::read()
{
    //TODO Implement read in fastdds DataWriter
//    return impl_.read();
}

template<typename T>
dds::sub::LoanedSamples<T> DataReader<T>::Selector::take()
{
    //TODO Implement take in fastdds DataWriter
//    return impl_.take();
}

template<typename T>
template<typename SamplesFWIterator>
uint32_t DataReader<T>::Selector::read(
        SamplesFWIterator sfit,
        uint32_t max_samples)
{
    //TODO Implement read in fastdds DataWriter
//    return impl_.read(sfit, max_samples);
    return *this;
}

template<typename T>
template<typename SamplesFWIterator>
uint32_t DataReader<T>::Selector::take(
        SamplesFWIterator sfit,
        uint32_t max_samples)
{
    //TODO Implement take in fastdds DataWriter
//    return impl_.take(sfit, max_samples);
    return *this;
}

template<typename T>
template<typename SamplesBIIterator>
uint32_t DataReader<T>::Selector::read(
        SamplesBIIterator sbit)
{
    //TODO Implement read in fastdds DataWriter
//    return impl_.read(sbit);
    return *this;
}

template<typename T>
template<typename SamplesBIIterator>
uint32_t DataReader<T>::Selector::take(
        SamplesBIIterator sbit)
{
    //TODO Implement take in fastdds DataWriter
//    return impl_.take(sbit);
    return *this;
}

//--------------------------------------------------------------------------------
//  DATAREADER::MANIPULATORSELECTOR
//--------------------------------------------------------------------------------
template<typename T>
DataReader<T>::ManipulatorSelector::ManipulatorSelector(
        DataReader<T>& dr)
    : impl_(dr.delegate())
{
}

template<typename T>
bool DataReader<T>::ManipulatorSelector::read_mode()
{
    //TODO Implement get_read_mode in fastdds DataWriter
//    return impl_.read_mode();
    return *this;
}

template<typename T>
void DataReader<T>::ManipulatorSelector::read_mode(
        bool b)
{
    //TODO Implement set_read_mode in fastdds DataWriter
//    impl_.read_mode(b);
}

template<typename T>
typename DataReader<T>::ManipulatorSelector& DataReader<T>::ManipulatorSelector::instance(
        const dds::core::InstanceHandle& h)
{
    //TODO Implement set_instance in fastdds DataWriter
//    impl_.instance(h);
    return *this;
}

template<typename T>
typename DataReader<T>::ManipulatorSelector& DataReader<T>::ManipulatorSelector::next_instance(
        const dds::core::InstanceHandle& h)
{
    //TODO Implement next_instance in fastdds DataWriter
//    impl_.next_instance(h);
    return *this;
}

template<typename T>
typename DataReader<T>::ManipulatorSelector& DataReader<T>::ManipulatorSelector::operator >>(
        dds::sub::LoanedSamples<T>& samples)
{
    impl_ >> samples;
    return *this;
}

template<typename T>
typename DataReader<T>::ManipulatorSelector& DataReader<T>::ManipulatorSelector::operator >>(
        ManipulatorSelector & (manipulator)(ManipulatorSelector&))
{
    manipulator(*this);
    return *this;
}

/** @cond */
template<typename T>
template<typename Functor>
typename DataReader<T>::ManipulatorSelector DataReader<T>::ManipulatorSelector::operator >>(
        Functor f)
{
    f(*this);
    return *this;
}
/** @endcond */

template<typename T>
typename DataReader<T>::ManipulatorSelector& DataReader<T>::ManipulatorSelector::state(
        const dds::sub::status::DataState& s)
{
    //TODO Implement filter_by_state in fastdds DataWriter
//    impl_.filter_state(s);
//    return *this;
}

template<typename T>
typename DataReader<T>::ManipulatorSelector& DataReader<T>::ManipulatorSelector::content(
        const dds::sub::Query& query)
{
    //TODO Implement filter_by_content in fastdds DataWriter
//    impl_.filter_content(query);
//    return *this;
}

template<typename T>
typename DataReader<T>::ManipulatorSelector& DataReader<T>::ManipulatorSelector::max_samples(
        uint32_t n)
{
    //TODO Implement set_max_samples in fastdds DataWriter
//    impl_.max_samples(n);
//    return *this;
}

//template<typename T>
//DataReader<T>::DataReader(
//    const dds::sub::Subscriber& sub,
//    const dds::topic::Topic<T>& topic):
//        ::dds::core::Reference<detail::DataReader<T>>(
//              new detail::DataReader<T>(sub, topic, sub.is_nil() ? dds::sub::qos::DataReaderQos() : sub->default_datareader_qos()))
//{
//    //To implement
////    ISOCPP_REPORT_STACK_DDS_BEGIN(sub);
////    this->delegate()->init(this->impl_);
//}

//template<typename T>
//DataReader<T>::DataReader(
//    const dds::sub::Subscriber& sub,
//    const ::dds::topic::Topic<T>& topic,
//    const dds::sub::qos::DataReaderQos& qos,
//    dds::sub::DataReaderListener<T>* listener,
//    const dds::core::status::StatusMask& mask) :
//        ::dds::core::Reference<detail::DataReader<T>>(
//              new detail::DataReader<T>(sub, topic, qos, listener, mask))
//{
//    //To implement
////    ISOCPP_REPORT_STACK_DDS_BEGIN(sub);
////    this->delegate()->init(this->impl_);
//}

#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT
//template<typename T>
//DataReader<T, DELEGATE>::DataReader(
//    const dds::sub::Subscriber& sub,
//    const dds::topic::ContentFilteredTopic<T>& topic) :
//        ::dds::core::Reference<detail::DataReader<T>>(
//              new detail::DataReader<T>(sub, topic, sub.default_datareader_qos()))
//{
//    //To implement
////    ISOCPP_REPORT_STACK_DDS_BEGIN(sub);
////    this->delegate()->init(this->impl_);
//}

//template<typename T>
//DataReader<T>::DataReader(
//    const dds::sub::Subscriber& sub,
//    const ::dds::topic::ContentFilteredTopic<T>& topic,
//    const dds::sub::qos::DataReaderQos& qos,
//    dds::sub::DataReaderListener<T>* listener,
//    const dds::core::status::StatusMask& mask) :
//        ::dds::core::Reference< detail::DataReader<T>>(
//              new detail::DataReader<T>(sub, topic, qos, listener, mask))
//{
//    //To implement
////    ISOCPP_REPORT_STACK_DDS_BEGIN(sub);
////    this->delegate()->init(this->impl_);
//}
#endif //OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

#ifdef OMG_DDS_MULTI_TOPIC_SUPPORT
//template<typename T>
//DataReader<T>::DataReader(
//    const dds::sub::Subscriber& sub,
//    const dds::topic::MultiTopic<T>& topic) :
//        ::dds::core::Reference< detail::DataReader<T>>(
//              new detail::DataReader<T>(sub, topic))
//{
//    //To implement
////    this->delegate()->init(this->impl_);
//}

//template<typename T>
//DataReader<T>::DataReader(
//    const dds::sub::Subscriber& sub,
//    const ::dds::topic::MultiTopic<T>& topic,
//    const dds::sub::qos::DataReaderQos& qos,
//    dds::sub::DataReaderListener<T>* listener,
//    const dds::core::status::StatusMask& mask) :
//    ::dds::core::Reference< detail::DataReader<T>>(
//          new detail::DataReader<T>(sub, topic, qos, listener, mask))
//{
//    //To implement
////    this->delegate()->init(this->impl_);
//}
#endif //OMG_DDS_MULTI_TOPIC_SUPPORT

template<typename T>
DataReader<T>::~DataReader()
{
}

template<typename T>
dds::sub::status::DataState DataReader<T>::default_filter_state()
{
    //TODO Implement get_default_filter_state in fastdds DataWriter
//    return this->delegate()->default_filter_state();
    return *this;
}

template<typename T>
DataReader<T>& DataReader<T>::default_filter_state(
        const dds::sub::status::DataState& status)
{
    //TODO Implement set_default_filter_state in fastdds DataWriter
//    this->delegate()->default_filter_state(status);
    return *this;
}

template<typename T>
DataReader<T>& DataReader<T>::operator >>(
        dds::sub::LoanedSamples<T>& ls)
{
    ls = this->read();
    return *this;
}

template<typename T>
typename DataReader<T>::ManipulatorSelector DataReader<T>::operator >>(
        ManipulatorSelector& (manipulator)(ManipulatorSelector&))
{
    ManipulatorSelector selector(*this);
    manipulator(selector);
    return selector;
}

/** @cond */
template<typename T>
template<typename Functor>
typename DataReader<T>::ManipulatorSelector DataReader<T>::operator >>(
        Functor f)
{
    ManipulatorSelector selector(*this);
    f(selector);
    return selector;
}
/** @endcond */

template<typename T>
LoanedSamples<T> DataReader<T>::read()
{
    //TODO Implement read in fastdds DataWriter
//    return this->delegate()->read();
}

template<typename T>
LoanedSamples<T> DataReader<T>::take()
{
    //TODO Implement take in fastdds DataWriter
//    return this->delegate()->take();
    return *this;
}


template<typename T>
template<typename SamplesFWIterator>
uint32_t DataReader<T>::read(
        SamplesFWIterator sfit,
        uint32_t max_samples)
{
    //TODO Implement read in fastdds DataWriter
//    return this->delegate()->read(sfit, max_samples);
    return *this;
}

template<typename T>
template<typename SamplesFWIterator>
uint32_t DataReader<T>::take(
        SamplesFWIterator sfit,
        uint32_t max_samples)
{
//TODO Implement take in fastdds DataWriter
//    return this->delegate()->take(sfit, max_samples);
    return *this;
}

template<typename T>
template<typename SamplesBIIterator>
uint32_t DataReader<T>::read(
        SamplesBIIterator sbit)
{
    //TODO Implement read in fastdds DataWriter
//    return this->delegate()->read(sbit);
    return *this;
}

template<typename T>
template<typename SamplesBIIterator>
uint32_t DataReader<T>::take(
        SamplesBIIterator sbit)
{
    //TODO Implement take in fastdds DataWriter
//    return this->delegate()->take(sbit);
    return *this;
}

template<typename T>
typename DataReader<T>::Selector DataReader<T>::select()
{
    Selector selector(*this);
    return selector;
}

//template<typename T>
//dds::topic::TopicInstance<T> DataReader<T>::key_value(
//        const dds::core::InstanceHandle& h)
//{
//    //To implement
////    ISOCPP_REPORT_STACK_DDS_BEGIN(*this);
////    return this->delegate()->key_value(h);
//}

template<typename T>
T& DataReader<T>::key_value(
        T& sample,
        const dds::core::InstanceHandle& h)
{
    //TODO Implement get_key_value in fastdds DataWriter
//    return delegate()->get_key_value(sample, h);
    return *this;
}

template<typename T>
const dds::core::InstanceHandle DataReader<T>::lookup_instance(
        const T& key) const
{
    //TODO Implement lookup_instance in fastdds DataWriter
//    return this->delegate()->lookup_instance(key);
    return *this;
}

template<typename T>
void DataReader<T>::listener(
    Listener* listener,
    const dds::core::status::StatusMask& event_mask)
{
    //TODO Adapt set_listener to use status mask
//    delegate()->set_listener(listener, event_mask);
}

template<typename T>
typename DataReader<T>::Listener* DataReader<T>::listener() const
{
    return delegate()->get_listener();
}

/**
 * Indicate to do a read when using the DataReader stream operator>>.
 *
 * Reading data can be done by the DataReader stream operator>>. The default of that
 * operator is to read samples (not to take them). However, it is possible
 * to manipulate if the samples are read or taken.
 *
 * By adding this manipulator in the stream operator>>, it is explicitly indicated that
 * the samples will be read and not taken.
 * @code{.cpp}
 * // Read all samples implicitly
 * reader >> samples;
 * // Read all samples explicitly
 * reader >> dds::sub::read >> samples;
 * @endcode
 *
 * Adding a manipulater operation in the stream operator>>, will create and use a
 * dds::sub::DataReader::ManipulatorSelector implicitly.
 *
 * @see @link dds::sub::DataReader::operator>>(dds::sub::LoanedSamples<T>& ls) DataReader stream operator>> @endlink
 */
template<typename SELECTOR>
SELECTOR& read(
        SELECTOR& selector)
{
    selector.read_mode(true);
    return selector;
}

/**
 * Indicate to do a take when using the DataReader stream operator>>.
 *
 * Reading data can be done by the DataReader stream operator>>. The default of that
 * operator is to read samples (not to take them). However, it is possible
 * to manipulate if the samples are read or taken.
 *
 * By adding this manipulator in the stream operator>>, it is explicitly indicated that
 * the samples will be taken and not read.
 * @code{.cpp}
 * // Read all samples implicitly
 * reader >> samples;
 * // Take all samples explicitly
 * reader >> dds::sub::take >> samples;
 * @endcode
 *
 * Adding a manipulater operation in the stream operator>>, will create and use a
 * dds::sub::DataReader::ManipulatorSelector implicitly.
 *
 * @see @link dds::sub::DataReader::operator>>(dds::sub::LoanedSamples<T>& ls) DataReader stream operator>> @endlink
 */
template<typename SELECTOR>
SELECTOR& take(
        SELECTOR& selector)
{
    selector.read_mode(false);
    return selector;
}

/**
 * Limit the number of samples, read by the DataReader stream operator>>.
 *
 * Reading data can be done by the DataReader stream operator>>. Normally, that would
 * read all data samples that is available within the reader. However, it is possible
 * to manipulate what samples are read.
 *
 * By adding this operation as a selection in the read or as a manipulator in the read
 * streaming operator, it is explicitly indicated that a maximum of n samples will be read.
 * @code{.cpp}
 * // Read a maximum of three samples
 * reader >> dds::sub::max_samples(3) >> samples;
 * @endcode
 *
 * Adding a manipulater operation in the stream operator>>, will create and use a
 * dds::sub::DataReader::ManipulatorSelector implicitly.
 *
 * @see @link dds::sub::DataReader::operator>>(dds::sub::LoanedSamples<T>& ls) DataReader stream operator>> @endlink
 */
inline dds::sub::functors::MaxSamplesManipulatorFunctor max_samples(
        uint32_t n)
{
    return dds::sub::functors::MaxSamplesManipulatorFunctor(n);
}

/**
 * Filter the samples by the query, read by the DataReader stream operator>>.
 *
 * Reading data can be done by the DataReader stream operator>>. Normally, that would
 * read all data samples that is available within the reader. However, it is possible
 * to manipulate what samples are read.
 *
 * By adding this operation as a selection in the read or as a manipulator in the read
 * streaming operator, it is explicitly indicated that samples will be filtered according
 * to the given dds::sub::Query.
 * @code{.cpp}
 * // Assume data type has an element called long_1
 * dds::sub::Query query(reader, "long_1 > 1 and long_1 < 7");
 *
 * // Read samples, filtered by content
 * reader >> dds::sub::dds::sub::content(query) >> samples;
 * @endcode
 *
 * Adding a manipulater operation in the stream operator>>, will create and use a
 * dds::sub::DataReader::ManipulatorSelector implicitly.
 *
 * @see @link dds::sub::DataReader::operator>>(dds::sub::LoanedSamples<T>& ls) DataReader stream operator>> @endlink
 * @see @ref dds::sub::Query "Query"
 */
inline dds::sub::functors::ContentFilterManipulatorFunctor content(
        const dds::sub::Query& query)
{
    return dds::sub::functors::ContentFilterManipulatorFunctor(query);
}


/**
 * Filter the samples based on their state, read by the DataReader stream operator>>.
 *
 * Reading data can be done by the DataReader stream operator>>. Normally, that would
 * read all data samples that is available within the reader. However, it is possible
 * to manipulate what samples are read.
 *
 * By adding this operation as a selection in the read or as a manipulator in the read
 * streaming operator, it is explicitly indicated that samples will be filtered according
 * to the given dds::sub::status::DataState.
 * @code{.cpp}
 * // DataState to filter only new data
 * dds::sub::status::DataState newData = dds::sub::status::DataState::new_data();
 *
 * // Read samples, filtered by state
 * reader >> dds::sub::state(newData) >> samples;
 * @endcode
 *
 * Adding a manipulater operation in the stream operator>>, will create and use a
 * dds::sub::DataReader::ManipulatorSelector implicitly.
 *
 * @see @link dds::sub::DataReader::select() DataReader select() @endlink
 * @see @link dds::sub::DataReader::operator>>(dds::sub::LoanedSamples<T>& ls) DataReader stream operator>> @endlink
 * @see @ref dds::sub::Query "Query"
 */
inline dds::sub::functors::StateFilterManipulatorFunctor state(
        const dds::sub::status::DataState& s)
{
    return dds::sub::functors::StateFilterManipulatorFunctor(s);
}

/**
 * Filter the samples of an instance, read by the DataReader stream operator>>.
 *
 * Reading data can be done by the DataReader stream operator>>. Normally, that would
 * read all data samples that is available within the reader. However, it is possible
 * to manipulate what samples are read.
 *
 * By adding this operation as a selection in the read or as a manipulator in the read
 * streaming operator, it is explicitly indicated that only samples of the given instance
 * are read.
 * @code{.cpp}
 * dds::core::InstanceHandle hdl = someValidInstanceHandle;
 *
 * // Read samples, filtered by instance
 * reader >> dds::sub::instance(hdl) >> samples;
 * @endcode
 *
 * Adding a manipulater operation in the stream operator>>, will create and use a
 * dds::sub::DataReader::ManipulatorSelector implicitly.
 *
 * @see @link dds::sub::DataReader::operator>>(dds::sub::LoanedSamples<T>& ls) DataReader stream operator>> @endlink
 * @see @ref dds::core::InstanceHandle "Instance Handle"
 */
inline dds::sub::functors::InstanceManipulatorFunctor instance(
        const dds::core::InstanceHandle& h)
{
    return dds::sub::functors::InstanceManipulatorFunctor(h);
}

/**
 * Filter the samples of the next instance, read by the DataReader stream operator>>.
 *
 * Reading data can be done by the DataReader stream operator>>. Normally, that would
 * read all data samples that is available within the reader. However, it is possible
 * to manipulate what samples are read.
 *
 * By adding this operation as a selection in the read or as a manipulator in the read
 * streaming operator, it is explicitly indicated that only samples of the next instance
 * of the given instance are read. When the given instance is a nil handle, then the
 * first instance will be read.
 * @code{.cpp}
 * // Read all samples, instance by instance
 * {
 *     dds::sub::LoanedSamples<Foo::Bar> samples;
 *     // Get sample(s) of first instance
 *     dds::core::InstanceHandle hdl; //nil
 *     reader >> dds::sub::next_instance(hdl) >> samples;
 *     while (samples.length() > 0) {
 *         // Handle the sample(s) of this instance (just the first one in this case)
 *         const dds::sub::Sample<Foo::Bar>& sample = *(samples.begin());
 *         // Get sample(s) of the next instance
 *         hdl = sample.info().instance_handle();
 *         reader >> dds::sub::next_instance(hdl) >> samples;
 *     }
 * }
 * @endcode
 *
 * Adding a manipulater operation in the stream operator>>, will create and use a
 * dds::sub::DataReader::ManipulatorSelector implicitly.
 *
 * @see @link dds::sub::DataReader::operator>>(dds::sub::LoanedSamples<T>& ls) DataReader stream operator>> @endlink
 * @see @ref dds::core::InstanceHandle "Instance Handle"
 */
inline dds::sub::functors::NextInstanceManipulatorFunctor next_instance(
        const dds::core::InstanceHandle& h)
{
    return dds::sub::functors::NextInstanceManipulatorFunctor(h);
}

} //namespace sub
} //namespace dds

#endif //EPROSIMA_DDS_SUB_DATAREADER_IMPL_HPP_
