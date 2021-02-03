Shared Libraries
================

## dollarconsensus

The purpose of this library is to make the verification functionality that is critical to Dollar's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `dollarconsensus.h` located in  `src/script/dollarconsensus.h`.

#### Version

`dollarconsensus_version` returns an `unsigned int` with the API version *(currently at an experimental `0`)*.

#### Script Validation

`dollarconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `dollarconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `dollarconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `dollarconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/dollar/bips/blob/master/bip-0016.mediawiki)) subscripts
- `dollarconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/dollar/bips/blob/master/bip-0066.mediawiki)) compliance
- `dollarconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY` - Enforce NULLDUMMY ([BIP147](https://github.com/dollar/bips/blob/master/bip-0147.mediawiki))
- `dollarconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY` - Enable CHECKLOCKTIMEVERIFY ([BIP65](https://github.com/dollar/bips/blob/master/bip-0065.mediawiki))
- `dollarconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY` - Enable CHECKSEQUENCEVERIFY ([BIP112](https://github.com/dollar/bips/blob/master/bip-0112.mediawiki))
- `dollarconsensus_SCRIPT_FLAGS_VERIFY_WITNESS` - Enable WITNESS ([BIP141](https://github.com/dollar/bips/blob/master/bip-0141.mediawiki))

##### Errors
- `dollarconsensus_ERR_OK` - No errors with input parameters *(see the return value of `dollarconsensus_verify_script` for the verification status)*
- `dollarconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `dollarconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `dollarconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`
- `dollarconsensus_ERR_AMOUNT_REQUIRED` - Input amount is required if WITNESS is used

### Example Implementations
- [NDollar](https://github.com/NicolasDorier/NDollar/blob/master/NDollar/Script.cs#L814) (.NET Bindings)
- [node-libdollarconsensus](https://github.com/bitpay/node-libdollarconsensus) (Node.js Bindings)
- [java-libdollarconsensus](https://github.com/dexX7/java-libdollarconsensus) (Java Bindings)
- [dollarconsensus-php](https://github.com/Bit-Wasp/dollarconsensus-php) (PHP Bindings)
