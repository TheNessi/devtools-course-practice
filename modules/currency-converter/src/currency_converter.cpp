// Copyright 2018 Grishin Anton

#include "include/currency_converter.h"
#include <limits>
#include <string>

const double eps = std::numeric_limits<double>::epsilon();

CurrencyConverter::CurrencyConverter() : usd_price(60), eur_price(75) {}

CurrencyConverter::CurrencyConverter(const double usd, const double eur)
                      : usd_price(usd), eur_price(eur) {}

CurrencyConverter::CurrencyConverter(const CurrencyConverter& z)
                      : usd_price(z.getUsdPrice()),
                        eur_price(z.getEurPrice()) {}

CurrencyConverter& CurrencyConverter::operator=(const CurrencyConverter& z) {
    usd_price = z.getUsdPrice();
    eur_price = z.getEurPrice();

    return *this;
}

double CurrencyConverter::getUsdPrice() const {
    return usd_price;
}

double CurrencyConverter::getEurPrice() const {
    return eur_price;
}


void CurrencyConverter::setUsdPrice(const double usd) {
    usd_price = usd;
}

void CurrencyConverter::setEurPrice(const double eur) {
    eur_price = eur;
}

double CurrencyConverter::roubleToDollar(double rub) {
    if (equalsZero(
        (this->getUsdPrice()))) throw std::string("Can't divide by zero");
    return rub / (this->getUsdPrice());
}

double CurrencyConverter::dollarToRouble(double usd) {
    return usd * (this->getUsdPrice());
}

double CurrencyConverter::roubleToEuro(double rub) {
    if (equalsZero(
        (this->getEurPrice()))) throw std::string("Can't divide by zero");
    return rub / (this->getEurPrice());
}

double CurrencyConverter::euroToRouble(double eur) {
    return eur * (this->getEurPrice());
}

double CurrencyConverter::dollarToEuro(double usd) {
    if (equalsZero(
        (this->getEurPrice()))) throw std::string("Can't divide by zero");
    return usd * (this->getUsdPrice()) / (this->getEurPrice());
}

double CurrencyConverter::euroToDollar(double eur) {
    if (equalsZero(
        (this->getUsdPrice()))) throw std::string("Can't divide by zero");
    return eur * (this->getEurPrice()) / (this->getUsdPrice());
}

bool CurrencyConverter::equalsZero(const double& value) const {
    return (value < eps && value > -eps);
}

bool CurrencyConverter::operator == (const CurrencyConverter& currency) const {
    if (((this->getUsdPrice() - currency.getUsdPrice()) == 0) &&
      ((this->getEurPrice() - currency.getEurPrice()) == 0)) return true;
    return false;
}

bool CurrencyConverter::operator != (const CurrencyConverter& currency) const {
    return !(*this == currency);
}
