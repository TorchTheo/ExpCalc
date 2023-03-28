#include "include/Var.h"
#include "include/Constant.h"
#include <string>

Var::Var(std::string _var_name, long long a) : var_name(_var_name), val(Number(a)) {}

Var::Var(std::string _var_name, float a) : var_name(_var_name), val(Number(a)) {}

Var::Var(std::string _var_name, Number _val) : var_name(_var_name), val(_val) {}

Number Var::getVal() const{
    return val;
}

std::string Var::getVarName() const {
    return var_name;
}

Number Var::operator-(const Number& a) const {
    Number *ret = new Number(val - a);
    return *ret;
}

Number Var::operator+(const Number& a) const {
    Number *ret = new Number(val + a);
    return *ret;
}

Number Var::operator*(const Number& a) const {
    Number *ret = new Number(val * a);
    return *ret;
}

Number Var::operator/(const Number& a) const {
    if ((a.type == Number::INT && a.val.i == 0) || (a.type == Number::FLOAT && a.val.f == 0))
        throw DEVIDE_ZERO;
    Number *ret = new Number(val / a);
    return *ret;
}

Number Var::operator+(const Var& var) const {
    Number *ret = new Number(val + var.getVal());
    return *ret;
}

Number Var::operator-(const Var& var) const {
    Number *ret = new Number(val - var.getVal());
    return *ret;
}

Number Var::operator*(const Var& var) const {
    Number *ret = new Number(val * var.getVal());
    return *ret;
}

Number Var::operator/(const Var& var) const {
    if ((var.getVal().type == Number::INT && var.getVal().val.i == 0) || (var.getVal().type == Number::FLOAT && var.getVal().val.f == 0))
        throw DEVIDE_ZERO;
    Number *ret = new Number(val / var.getVal());
    return *ret;
}

Number::Number(long long a) {
    type = INT;
    val.i = a;
}

Number::Number(float a) {
    if (a == 0) {
        type = INT;
        val.i = a;
    } else {
        type = FLOAT;
        val.f = a;
    }
}

Number::Number(TYPE t) : type(t) {
    if (t == INT)
        val.i = 0;
    else 
        val.f = 0;
}

Number::Number(const Number& t) {
    type = t.type;
    switch(type) {
    case INT:
        val.i = t.val.i;
        break;
    case FLOAT:
        val.f = t.val.f;
        break;
    }
}

Number Number::operator+(const Number& a) const {
    if (a.type == FLOAT || type == FLOAT) {
        Number* ret = new Number(FLOAT);
        if (a.type == FLOAT && type == FLOAT)
            ret->val.f = val.f + a.val.f;
        else if (a.type == FLOAT && type == INT)
            ret->val.f = val.i + a.val.f;
        else if(a.type == INT && type == FLOAT)
            ret->val.f = val.f + a.val.i;
        return *ret;
    } else {
        Number *ret = new Number(INT);
        ret->val.i = a.val.i + val.i;
        return *ret;
    }
}

Number Number::operator-(const Number& a) const {
    if (a.type == FLOAT || type == FLOAT) {
        Number* ret = new Number(FLOAT);
        if (a.type == FLOAT && type == FLOAT)
            ret->val.f = val.f - a.val.f;
        else if (a.type == FLOAT && type == INT)
            ret->val.f = val.i - a.val.f;
        else if(a.type == INT && type == FLOAT)
            ret->val.f = val.f - a.val.i;
        return *ret;
    } else {
        Number *ret = new Number(INT);
        ret->val.i = val.i - a.val.i;
        return *ret;
    }
}

Number Number::operator*(const Number& a) const {
    if (a.type == FLOAT || type == FLOAT) {
        Number* ret = new Number(FLOAT);
        if (a.type == FLOAT && type == FLOAT)
            ret->val.f = val.f * a.val.f;
        else if (a.type == FLOAT && type == INT)
            ret->val.f = val.i * a.val.f;
        else if(a.type == INT && type == FLOAT)
            ret->val.f = val.f * a.val.i;
        return *ret;
    } else {
        Number *ret = new Number(INT);
        ret->val.i = a.val.i * val.i;
        return *ret;
    }
}

Number Number::operator/(const Number& a) const {
    if ((a.type == Number::INT && a.val.i == 0) || (a.type == Number::FLOAT && a.val.f == 0))
        throw DEVIDE_ZERO;
    Number *ret = new Number(FLOAT);
    if (a.type == FLOAT && type == FLOAT)
        ret->val.f = val.f / a.val.f;
    else if (a.type == FLOAT && type == INT)
        ret->val.f = val.i / a.val.f;
    else if(a.type == INT && type == FLOAT)
        ret->val.f = val.f / a.val.i;
    else
        ret->val.f = static_cast<float>(val.i) / a.val.i;
    return *ret;
}

Number Number::operator+(const Var& var) const {
    Number *ret = new Number(*this + var.getVal());
    return *ret;
}

Number Number::operator-(const Var& var) const {
    Number *ret = new Number(*this - var.getVal());
    return *ret;
}

Number Number::operator*(const Var& var) const {
    Number *ret = new Number(*this * var.getVal());
    return *ret;
}

Number Number::operator/(const Var& var) const {
    if ((var.getVal().type == Number::INT && var.getVal().val.i == 0) || (var.getVal().type == Number::FLOAT && var.getVal().val.f == 0))
        throw DEVIDE_ZERO;
    Number *ret = new Number(*this / var.getVal());
    return *ret;
}