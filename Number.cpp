#include "include/Number.h"

Number::Number(long long a) {
    type = INT;
    val.i = a;
}

Number::Number(float a) {
    type = FLOAT;
    val.f = a;
}

Number::Number(TYPE t) : type(t) {
    if (t == INT)
        val.i = 0;
    else 
        val.f = 0;
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