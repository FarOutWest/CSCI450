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

FacetCommandNode::FacetCommandNode(const NodePtr &planea, const NodePtr &planeb, const NodePtr &planec) {
  children.push_back(planea);
  children.push_back(planeb);
  children.push_back(planec);
}

int FacetCommandNode::type() const { return FACET_COMMAND; }
void FacetCommandNode::print(std::ostream &out) const {
  out << "facet(planea=" << children.at(0)
      << ", planec=" << children.at(1)
      << ", planeb=" << children.at(2) << ")";
}

int FacetCommandNode::planea() const {
  return std::dynamic_pointer_cast<NumberNode>(children.at(0))->number;
}

int FacetCommandNode::planeb() const {
  return std::dynamic_pointer_cast<NumberNode>(children.at(1))->number;
}

int FacetCommandNode::planec() const {
  return std::dynamic_pointer_cast<NumberNode>(children.at(2))->number;
}

OuterloopCommandNode::OuterloopCommandNode(const NodePtr &vertexa, const NodePtr &vertexb, const NodePtr &vertexc) {
  children.push_back(vertexa);
  children.push_back(vertexb);
  children.push_back(vertexc);
}

int OuterloopCommandNode::type() const { return OUTERLOOP_COMMAND; }
void OuterloopCommandNode::print(std::ostream &out) const {
  out << "facet(vertexa=" << children.at(0)
      << ", vertexb=" << children.at(1)
      << ", vertexc=" << children.at(2) << ")";
}

int OuterloopCommandNode::vertexa() const {
  return std::dynamic_pointer_cast<NumberNode>(children.at(0))->number;
}

int OuterloopCommandNode::vertexb() const {
  return std::dynamic_pointer_cast<NumberNode>(children.at(1))->number;
}

int OuterloopCommandNode::vertexc() const {
  return std::dynamic_pointer_cast<NumberNode>(children.at(2))->number;
}

EndloopCommandNode::EndloopCommandNode(const NodePtr &target) {
  children.push_back(target);
}

int EndloopCommandNode::type() const { return ENDLOOP_COMMAND; }
void EndloopCommandNode::print(std::ostream &out) const {
  out << "stop(target=" << children.at(0) << ")";
}

const std::string & EndloopCommandNode::target() const {
  return std::dynamic_pointer_cast<WordNode>(children.at(0))->word;
}

EndfacetCommandNode::EndfacetCommandNode(const NodePtr &target) {
  children.push_back(target);
}

int EndfacetCommandNode::type() const { return ENDFACET_COMMAND; }
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
