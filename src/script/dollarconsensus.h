// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Copyright (c) 2021 The Dollar Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DOLLAR_SCRIPT_DOLLARCONSENSUS_H
#define DOLLAR_SCRIPT_DOLLARCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_DOLLAR_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/dollar-config.h>
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBDOLLARCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define DOLLARCONSENSUS_API_VER 1

typedef enum dollarconsensus_error_t
{
    dollarconsensus_ERR_OK = 0,
    dollarconsensus_ERR_TX_INDEX,
    dollarconsensus_ERR_TX_SIZE_MISMATCH,
    dollarconsensus_ERR_TX_DESERIALIZE,
    dollarconsensus_ERR_AMOUNT_REQUIRED,
    dollarconsensus_ERR_INVALID_FLAGS,
} dollarconsensus_error;

/** Script verification flags */
enum
{
    dollarconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    dollarconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    dollarconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    dollarconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    dollarconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    dollarconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    dollarconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    dollarconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = dollarconsensus_SCRIPT_FLAGS_VERIFY_P2SH | dollarconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               dollarconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | dollarconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               dollarconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | dollarconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int dollarconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, dollarconsensus_error* err);

EXPORT_SYMBOL int dollarconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, dollarconsensus_error* err);

EXPORT_SYMBOL unsigned int dollarconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // DOLLAR_SCRIPT_DOLLARCONSENSUS_H
