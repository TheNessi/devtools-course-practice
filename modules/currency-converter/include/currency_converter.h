// Copyright 2018 Grishin Anton

#ifndef MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_H_
#define MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_H_


class CurrencyConverter {
 public:
    CurrencyConverter();
    CurrencyConverter(const double usd, const double eur);
    CurrencyConverter(const CurrencyConverter& z);

    CurrencyConverter& operator=(const CurrencyConverter& z);

    double getUsdPrice() const;
    double getEurPrice() const;

    void setUsdPrice(const double usd);
    void setEurPrice(const double eur);

    double roubleToDollar(double rub);
    double dollarToRouble(double usd);

    double roubleToEuro(double rub);
    double euroToRouble(double eur);

    double dollarToEuro(double usd);
    double euroToDollar(double eur);

    bool operator == (const CurrencyConverter& currency) const;
    bool operator != (const CurrencyConverter& currency) const;

 private:
    bool equalsZero(const double& value) const;
    double usd_price;
    double eur_price;
};

#endif  // MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_H_
