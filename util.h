/*!
 * \author Kaveen Hyacinth
 * \copyright Kaveen Hyacinth Digital © 2020
*/

#ifndef UTIL_H
#define UTIL_H

#include <QString>
#include <QStringList>

/*!
 * \brief The Util class does the formatting for the given strings and int types
 */
class Util
{
public:
    Util();

public:
    /*!
     * \brief FormatMoney returns int type of the balance when input the string type of the balance
     * \param balance is the amount of money to be formatted
     * \return the formatted int type of balance
     */
    int FormatMoney(QString balance);

    /*!
     * \brief FormatBalance concatinate amount and it s cents amount together
     * \param amount is the complete number value
     * \param cents is the fraction part of the money
     * \return concatinated balance string
     */
    QString FormatBalance(QString amount, QString cents);

    /*!
     * \brief FormatBalance split cents form the balance, cast those to string and finally concatinate together
     * \param balance is the int type of money
     * \return concatinated balance string
     */
    QString FormatBalance(int balance);

    /*!
     * \brief SplitBalance splits the blance into amount and cents.
     * \param balance is the string type of money
     * \return spplited string list of amount and cents
     */
    QStringList SplitBalance(QString balance);
};

#endif // UTIL_H
