
#include "ex1.h"

//constructors
UPlus::UPlus(Expression *expression) : UnaryOperator(expression) {}
UMinus::UMinus(Expression *expression) : UnaryOperator(expression){}

BinaryOperator::BinaryOperator(Expression *left_side, Expression *right_side) {
    this->left = left_side;
    this->right = right_side;
}

UnaryOperator::UnaryOperator(Expression *expression) {
    this->exp = expression;
}

Plus::Plus(Expression *left_side, Expression *right_side) : BinaryOperator(left_side, right_side){}
Minus::Minus(Expression *left_side, Expression *right_side) : BinaryOperator(left_side, right_side){}
Mul::Mul(Expression *left_side, Expression *right_side) : BinaryOperator(left_side, right_side){}
Div::Div(Expression *left_side, Expression *right_side) : BinaryOperator(left_side, right_side){}

Variable::Variable(string name_string, double val) {
    this->name = name_string;
    this->value = val;
}
Variable::Variable(const string &name, const string &simAddress, const string &simDirection, double value)
    : name(name), sim_Address(simAddress), sim_Direction(simDirection), value(value) {}

//functions
double Value::calculate() {
    return val;
}

double Plus::calculate() {
    return left->calculate() + right->calculate();
}

double Minus::calculate() {
    return left->calculate() - right->calculate();
}

double Mul::calculate() {
    return left->calculate() * right->calculate();
}

double Div::calculate() {
    double bad_division = right->calculate();
    if (bad_division == 0) {
        throw ("Division by 0");
    }
    return left->calculate() / bad_division;
}

double UPlus::calculate() {
    return exp->calculate();
}

double UMinus::calculate() {
    return -exp->calculate();
}

double Variable::calculate() {
    return value;
}

Variable& Variable::operator++() {
    value++;
    return *this;
}

Variable& Variable::operator++(int) {
    value++;
    return *this;
}

Variable& Variable::operator+=(double x) {
    value += x;
    return *this;
}

Variable& Variable::operator--() {
    value--;
    return *this;
}

Variable& Variable::operator--(int) {
    value--;
    return *this;
}

Variable& Variable::operator-=(double x) {
    value -= x;
    return *this;
}

//destructors
UnaryOperator::~UnaryOperator() {
    delete exp;
}

BinaryOperator::~BinaryOperator() {
    delete left;
    delete right;
}

Variable::~Variable() {}

const string &Variable::getName() const {
    return name;
}

const string &Variable::getSimAddress() const {
    return sim_Address;
}

const string &Variable::getSimDirection() const {
    return sim_Direction;
}

double Variable::getValue() const {
    return value;
}

void Variable::setName(const string &name) {
    Variable::name = name;
}

void Variable::setSimAddress(const string &simAddress) {
    sim_Address = simAddress;
}

void Variable::setSimDirection(const string &simDirection) {
    sim_Direction = simDirection;
}

void Variable::setValue(double value) {
    Variable::value = value;
}



UMinus::~UMinus() {}

UPlus::~UPlus() {}

Div::~Div() {}

Mul::~Mul() {}

Minus::~Minus() {}

Plus::~Plus() {}

Value::~Value() {}




Smaller_op::Smaller_op(Expression *leftSide, Expression *rightSide) : BinaryOperator(leftSide, rightSide) {}

double Smaller_op::calculate() {
    if (left->calculate() < right->calculate())
        return 1;
    return 0;
}

Smaller_op::~Smaller_op() {

}

Bigger_op::Bigger_op(Expression *leftSide, Expression *rightSide) : BinaryOperator(leftSide, rightSide) {}

double Bigger_op::calculate() {
   if (left->calculate() > right->calculate())
       return 1;
   return 0;
}

Bigger_op::~Bigger_op() {


}

Equal_op::Equal_op(Expression *leftSide, Expression *rightSide) : BinaryOperator(leftSide, rightSide) {}

double Equal_op::calculate() {
    if (left->calculate() == right->calculate())
        return 1;
    return 0;
}

Equal_op::~Equal_op() {

}

Not_eq_op::Not_eq_op(Expression *leftSide, Expression *rightSide) : BinaryOperator(leftSide, rightSide) {}

double Not_eq_op::calculate() {
    if (left->calculate() != right->calculate())
        return 1;
    return 0;
}

Not_eq_op::~Not_eq_op() {

}

Smaller_eq_op::Smaller_eq_op(Expression *leftSide, Expression *rightSide) : BinaryOperator(leftSide, rightSide) {}

double Smaller_eq_op::calculate() {
    if (left->calculate() <= right->calculate())
        return 1;
    return 0;
}

Smaller_eq_op::~Smaller_eq_op() {

}

Bigger_eq_op::Bigger_eq_op(Expression *leftSide, Expression *rightSide) : BinaryOperator(leftSide, rightSide) {}

double Bigger_eq_op::calculate() {
    if (left->calculate() >= right->calculate())
        return 1;
    return 0;
}

Bigger_eq_op::~Bigger_eq_op() {

}
