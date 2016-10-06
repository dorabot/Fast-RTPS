// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file Authentication.h	
 */
#ifndef _RTPS_SECURITY_CRYPTOGRAPHY_CRYPTOTYPES_H_
#define _RTPS_SECURITY_CRYPTOGRAPHY_CRYPTOTYPES_H_

#include "../../common/Token.h"
#include "../common/Handle.h"

namespace eprosima {
namespace fastrtps {
namespace rtps {
namespace security {

    typedef std::array<uint8_t,4> CryptoTransformKind;
    typedef std::array<uint8_t,4> CryptoTransformKeyId;

    typedef Token CryptoToken;
    typedef Token ParticipantCryptoToken;
    typedef Token DatawriterCryptoToken;
    typedef Token DatareaderCryptoToken;

    typedef std::vector<CryptoToken> CryptoTokenSeq;
    typedef CryptoTokenSeq ParticipantCryptoTokenSeq;
    typedef CryptoTokenSeq DatawriterCryptoTokenSeq;
    typedef CryptoTokenSeq DatareaderCryptoTokenSeq;

    struct CryptoTransformIdentifier{
        CryptoTransformKind transformation_kind;
        CryptoTransformKeyId transformation_key_id;
    };

    enum SecureSubmessageCategory_t: uint8_t
    {
        INFO_SUBMESSAGE = 0,
        DATAWRITER_SUBMESSAGE,
        DATAREADER_SUBMESSAGE
    };


} //namespace eprosima
} //namespace fastrtps
} //namespace rtps
} //namespace security

#endif //_RTPS_SECURITY_CRYPTOGRAPHY_CRYPTOTYPES_H_