//
// Created by bhyamy on 11/23/19.
//

#include "Interpreter.h"


Interpreter::Interpreter() {
    this->values = new unordered_map<string, Variable*>;
}
Interpreter::Interpreter(unordered_map<string, Variable *>* values) : values(values) {}


Interpreter::~Interpreter() {
    delete values;
}

Expression* Interpreter::interpret(string e) {
    auto* operand_stack = new stack<string>;
    auto* numbers_queue = new queue<string>;
    size_t current = 0;
    regex operand_regex("[\\(\\)/\\*\\-\\+]");
    regex not_variable_regex("\\W");
    regex variable_regex("\\w");
    regex numbers_regex("\\d*\\.?\\d*");
    regex not_numbers_regex("[^\\d\\.]");
    regex parenthesis ("[\\(\\)]");
    regex parenthesis_close ("\\)");
    int counter = 0;
    for (string::size_type i = 0; i < e.size(); i++) {
        if (e[i] == '(' ) {
            counter++;
        } else if (e[i] == ')') {
            counter--;
            if (counter < 0) {
                throw ("bad input1");
            }
        }
    }
    if (counter != 0) {
        throw ("bad input2");
    }
    while (current < e.size()) {
        string get;
        if (regex_match(e.substr(current, 1), operand_regex)) {
            string op = e.substr(current, 1);
            if (op == "(") {
                if (current != 0 && !(regex_match(e.substr(current - 1, 1), operand_regex) &&
                        !regex_match(e.substr(current - 1, 1), parenthesis_close)))
                {
                    if (regex_match(e.substr(current - 1, 1), operand_regex))
                        cout << "1";
                    if (!regex_match(e.substr(current - 1, 1), parenthesis_close))
                        cout << "2";
                    throw ("bad input3");
                }
                operand_stack->push(op);
            } else if (op == "+" || op == "-") {
                if (current != 0 && regex_match(e.substr(current - 1, 1), operand_regex) &&
                    !regex_match(e.substr(current - 1, 1), parenthesis))
                    throw ("bad input4");
                if (!operand_stack->empty() && regex_match(operand_stack->top(), operand_regex) &&
                    !regex_match(operand_stack->top(), parenthesis)) {
                    numbers_queue->push(operand_stack->top());
                    operand_stack->pop();
                    operand_stack->push(op);
                } else {
                    if (current != 0 && (get = e.substr(current - 1, 1)) == "(") {
                        operand_stack->push("~" + op);
                    } else
                        operand_stack->push(op);
                }
            } else if (op == "*" || op == "/") {
                if (current != 0 && regex_match(e.substr(current - 1, 1), operand_regex) &&
                    !regex_match(e.substr(current - 1, 1), parenthesis_close))
                    throw ("bad input5");
                if (!operand_stack->empty() && (operand_stack->top() == "*" || operand_stack->top() == "/")) {
                    numbers_queue->push(operand_stack->top());
                    operand_stack->pop();
                    operand_stack->push(op);
                } else {
                    operand_stack->push(op);
                }
            } else {
                if (current != 0 && regex_match(e.substr(current - 1, 1), operand_regex) &&
                    !regex_match(e.substr(current - 1, 1), parenthesis_close))
                    throw ("bad input6");
                while (operand_stack->top() != "(") {
                    numbers_queue->push(operand_stack->top());
                    operand_stack->pop();
                }
                operand_stack->pop();
            }
            current++;
        } else if (regex_match(e.substr(current, 1), numbers_regex)) {
            if (current != 0 && !(regex_match(e.substr(current - 1, 1), operand_regex) &&
            !regex_match(e.substr(current - 1, 1), parenthesis_close))) {
                throw ("bad input7");
            }
            smatch m;
            string e1 = e.substr(current);
            regex_search(e1, m, not_numbers_regex);
            string num = e1.substr(0, m.position());
            numbers_queue->push(num);
            current += m.position();
        } else if (regex_match(e.substr(current, 1), variable_regex)) {
            if (current != 0 && !(regex_match(e.substr(current - 1, 1), operand_regex) &&
                  !regex_match(e.substr(current - 1, 1), parenthesis_close))) {
                throw ("bad input8");
            }
            smatch m;
            string e2 = e.substr(current);
            regex_search(e2, m, not_variable_regex);
            string var = e2.substr(0, m.position());
            numbers_queue->push(var);
            current += m.position();
        } else {
            throw("bad input9");
        }
    }
    while (!operand_stack->empty()) {
        numbers_queue->push(operand_stack->top());
        operand_stack->pop();
    }
    delete(operand_stack);

    //creating the expression
    auto expression_stack = new stack<Expression*>;
    while (!numbers_queue->empty()) {
        string first = numbers_queue->front();
        numbers_queue->pop();
        if (regex_match(first, numbers_regex)) {
            expression_stack->push(new Value(stod(first)));
        } else if (regex_match(first, variable_regex)) {
            auto iter = values->find(first);
            if (iter != values->end()) {
                expression_stack->push(iter->second);
            } else {
                throw ("bad input10");
            }
        } else {
            Expression* new_exp;
            Expression* old_exp1;
            if (!expression_stack->empty()) {
                 old_exp1 = expression_stack->top();
                 expression_stack->pop();
            } else {
                throw ("bad input11");
            }

            Expression* old_exp2 = nullptr;
            if (!expression_stack->empty()) {
                old_exp2 = expression_stack->top();
                expression_stack->pop();
            }else {
                if ((first == "+" || first == "-") && expression_stack->size() == 0) {
                    first = "~" + first;
                }
                if (first[0] != '~')
                    throw ("bad input12");
            }
            if (first == "+") {
                new_exp = new Plus(old_exp2, old_exp1);
                expression_stack->push(new_exp);
            } else if (first == "-") {
                new_exp = new Minus(old_exp2, old_exp1);
                expression_stack->push(new_exp);
            } else if (first == "*") {
                new_exp = new Mul(old_exp2, old_exp1);
                expression_stack->push(new_exp);
            } else if (first == "/") {
                new_exp = new Div(old_exp2, old_exp1);
                expression_stack->push(new_exp);
            } else if (first == "~-") {
                if (old_exp2 != nullptr) {
                    expression_stack->push(old_exp2);
                }
                new_exp = new UMinus(old_exp1);
                expression_stack->push(new_exp);
            } else if (first == "~+") {
                if (old_exp2 != nullptr) {
                    expression_stack->push(old_exp2);
                }
                new_exp = new UPlus(old_exp1);
                expression_stack->push(new_exp);
            }
        }
    }
    delete numbers_queue;
    Expression* result = expression_stack->top();
    expression_stack->pop();
    if (!expression_stack->empty()) {
        throw ("bad input13");
    }
    delete expression_stack;
    return result;
}



void Interpreter::setVariables(const string& variables) {
    regex var_regex("\\W");
    regex num_regex1("^\\-?\\d*\\.?\\d*");
    double check_num;
    size_t current_semi = 0, check_semi, check_equals = 0;
    while (current_semi < variables.size()) {
        check_semi = variables.find(';', current_semi);
        if (check_semi == string::npos) {
            check_semi = variables.size();
        }
        string var = variables.substr(current_semi, check_semi - current_semi);
        current_semi = check_semi + 1;
        check_equals = var.find('=');
        if (check_equals == string::npos) {
            throw ("bad input14");
        }
        string name = var.substr(0, check_equals);
        if (regex_match(name, var_regex) || isdigit(name[0])) {
            throw ("bad input15");
        }
        string num = var.substr(check_equals + 1);
        if (!(regex_match(num, num_regex1))) {
            throw ("bad input16");
        }
        try {
            check_num = stod(num);
        } catch (invalid_argument) {
            throw ("bad input17");
        }
        ((*this->values)[name])->setValue(check_num);
    }
}