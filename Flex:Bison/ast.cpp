#include "ast.hpp"

Node::~Node() {};

WordNode::WordNode(const std::string &_word) {
  word = _word;
}

int WordNode::type() const {
  return WORD_LITERAL;
}

void WordNode::print(std::ostream &out) const {
  out << "word(" << word << ")";
}

NumberNode::NumberNode(int _number) {
  number = _number;
}

int NumberNode::type() const {
  return NUMBER_LITERAL;
}

void NumberNode::print(std::ostream &out) const {
  out << "number(" << number << ")";
}

FacetCommandNode::StartCommandNode(const NodePtr &target, const NodePtr &power) {
  children.push_back(target);
  children.push_back(power);
}

int FacetCommandNode::type() const { return START_COMMAND; }
void FacetCommandNode::print(std::ostream &out) const {
  out << "facet(target=" << children.at(0)
      << ", power=" << children.at(1) << ")";
}

const std::string & FacetCommandNode::target() const {
  return std::dynamic_pointer_cast<WordNode>(children.at(0))->word;
}

int FacetCommandNode::power() const {
  return std::dynamic_pointer_cast<NumberNode>(children.at(1))->number;
}

OuterloopCommandNode::StartCommandNode(const NodePtr &target, const NodePtr &power) {
  children.push_back(target);
  children.push_back(power);
}

int OuterloopCommandNode::type() const { return START_COMMAND; }
void OuterloopCommandNode::print(std::ostream &out) const {
  out << "facet(target=" << children.at(0)
      << ", power=" << children.at(1) << ")";
}

const std::string & OuterloopCommandNode::target() const {
  return std::dynamic_pointer_cast<WordNode>(children.at(0))->word;
}

int OuterloopCommandNode::power() const {
  return std::dynamic_pointer_cast<NumberNode>(children.at(1))->number;
}

EndloopCommandNode::StopCommandNode(const NodePtr &target) {
  children.push_back(target);
}

int EndloopCommandNode::type() const { return STOP_COMMAND; }
void EndloopCommandNode::print(std::ostream &out) const {
  out << "stop(target=" << children.at(0) << ")";
}

const std::string & EndloopCommandNode::target() const {
  return std::dynamic_pointer_cast<WordNode>(children.at(0))->word;
}

EndfacetCommandNode::StopCommandNode(const NodePtr &target) {
  children.push_back(target);
}

int EndfacetCommandNode::type() const { return STOP_COMMAND; }
void EndfacetCommandNode::print(std::ostream &out) const {
  out << "stop(target=" << children.at(0) << ")";
}

const std::string & EndfacetCommandNode::target() const {
  return std::dynamic_pointer_cast<WordNode>(children.at(0))->word;
}

int ProgramNode::type() const { return PROGRAM; }

void ProgramNode::print(std::ostream &out) const {
  out << "program(children=[" << std::endl;
  for (size_t i=0; i<children.size(); ++i) {
    out << "  " << children[i] << " // child " << i << std::endl;
  }
  out << "]) // program" << std::endl;
}

int number(const NodePtr &p) {
  return std::dynamic_pointer_cast < NumberNode >(p)->number;
}

const std::string & word(const NodePtr &p) {
  return std::dynamic_pointer_cast < WordNode >(p)->word;
}

NodePtr node(int number) {
  return NodePtr(new NumberNode(number));
}

NodePtr node(const std::string &word) {
  return NodePtr(new WordNode(word));
}

std::ostream &operator<< (std::ostream& out, const NodePtr &p) {
  p->print(out);
  return out;
}
