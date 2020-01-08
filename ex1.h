
#include <iostream>
#include "Expression.h"



#ifndef EX1IRIS_EX1_H
#define EX1IRIS_EX1_H


class Value : public Expression {
    const double val;
public:
    double calculate() override;
    Value(double value) : val(value) {}
    virtual ~Value();
};

class Variable : public Expression {
    string name;
    string sim_Address;
    string sim_Direction;
    double value;

public:
    Variable&operator++();
    Variable&operator--();
    Variable&operator+=(double x);
    Variable&operator-=(double x);
    Variable&operator++(int x);
    Variable&operator--(int x);
    double calculate() override;
    //ctor's
    Variable(string name_string, double val);

    Variable(const string &name1, const string &simAddress, const string &simDirection, double val);

    //dtor
    virtual ~Variable();

    const string &getName() const;
    const string &getSimAddress() const;
    const string &getSimDirection() const;
    double getValue() const;

    void setName(const string &name1);

    void setSimAddress(const string &simAddress);

    void setSimDirection(const string &simDirection);

    void setValue(double val);
};

class UnaryOperator : public Expression {
protected:
    Expression* exp;
public:
    UnaryOperator(Expression* expression);
    virtual ~UnaryOperator();
};

class UPlus : public UnaryOperator {
public:
    double calculate() override;
    UPlus(Expression* expression);
    virtual ~UPlus();
};

class UMinus : public UnaryOperator {
public:
    double calculate() override;
    UMinus(Expression* expression);
    virtual ~UMinus();
};

class BinaryOperator : public Expression {
protected:
    Expression* left;
    Expression* right;
public:
    BinaryOperator(Expression* left_side, Expression* right_side);
    virtual ~BinaryOperator();
};

class Plus : public BinaryOperator {
public:
    double calculate() override;
    Plus(Expression* left_side, Expression* right_side);
    virtual ~Plus();
};

class Minus : public BinaryOperator {
public:
    double calculate() override;
    Minus(Expression* left_side, Expression* right_side);
    virtual ~Minus();
};

class Mul : public BinaryOperator {
public:
    double calculate() override;
    Mul(Expression* left_side, Expression* right_side);
    virtual ~Mul();
};

class Div : public BinaryOperator {
public:
    double calculate() override;
    Div(Expression* left_side, Expression* right_side);
    virtual ~Div();
};

class Smaller_op : public BinaryOperator {
public:
    double calculate() override;
    Smaller_op(Expression *leftSide, Expression *rightSide);
    virtual ~Smaller_op();
};

class Bigger_op : public BinaryOperator {
public:
    Bigger_op(Expression *leftSide, Expression *rightSide);
    double calculate() override;
    virtual ~Bigger_op();
};

class Equal_op : public BinaryOperator {
public:
    Equal_op(Expression *leftSide, Expression *rightSide);
    double calculate() override;
    virtual ~Equal_op();
};

class Not_eq_op : public BinaryOperator {
public:
    Not_eq_op(Expression *leftSide, Expression *rightSide);
    double calculate() override;
    virtual ~Not_eq_op();
};

class Smaller_eq_op : public BinaryOperator {
public:
    Smaller_eq_op(Expression *leftSide, Expression *rightSide);
    double calculate() override;
    virtual ~Smaller_eq_op();
};

class Bigger_eq_op : public BinaryOperator {
public:
    Bigger_eq_op(Expression *leftSide, Expression *rightSide);
    double calculate() override;
    virtual ~Bigger_eq_op();
};

#endif //EX1IRIS_EX1_H
