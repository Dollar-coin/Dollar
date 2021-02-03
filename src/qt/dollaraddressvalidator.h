// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DOLLAR_QT_DOLLARADDRESSVALIDATOR_H
#define DOLLAR_QT_DOLLARADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class DollarAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit DollarAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Dollar address widget validator, checks for a valid dollar address.
 */
class DollarAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit DollarAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // DOLLAR_QT_DOLLARADDRESSVALIDATOR_H
