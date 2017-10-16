#pragma once

#include <vector>
#include <memory>
#include <string>
#include <iostream>

class Node {
public: enum {
    PROGRAM,
    FACET_COMMAND,
    OUTERLOOP_COMMAND,
    ENDFACET_COMMAND,
    ENDLOOP_COMMAND,
    WORD_LITERAL,
    NUMBER_LITERAL
  };
public: std::vector < std::shared_ptr < Node > > children;
public: virtual int type() const = 0;
public: virtual void print(std::ostream &out) const = 0;
public: virtual ~Node();
};

typedef std::shared_ptr < Node > NodePtr;

class WordNode : public Node {
public: std::string word;
public: WordNode(const std::string &_word);
public: int type() const;
public: void print(std::ostream &out) const;
};

typedef std::shared_ptr < WordNode > WordNodePtr;

class NumberNode : public Node {
public: int number;
public: NumberNode(int _number);
public: int type() const;
public: void print(std::ostream &out) const;
};

typedef std::shared_ptr < NumberNode > NumberNodePtr;


class FacetCommandNode : public Node {
public: FacetCommandNode(const NodePtr &planea, const NodePtr &planeb, const NodePtr &planec);
public: int type() const;
public: void print(std::ostream &out) const;

public: int planea() const;
public: int planeb() const;
public: int planec() const;

};

typedef std::shared_ptr < FacetCommandNode > FacetCommandNodePtr;

class EndfacetCommandNode : public Node {
public: EndfacetCommandNode(const NodePtr &target);
public: int type() const;
public: void print(std::ostream &out) const;

public: const std::string & target() const;

};

typedef std::shared_ptr < EndfacetCommandNode > EndfacetCommandNodePtr;

class OuterloopCommandNode : public Node {
public: OuterloopCommandNode(const NodePtr &vertexa, const NodePtr &vertexb, const NodePtr &vertexc);
public: int type() const;
public: void print(std::ostream &out) const;

public: int vertexa() const;
public: int vertexb() const;
public: int vertexc() const;

};

typedef std::shared_ptr < OuterloopCommandNode > OtuerloopCommandNodePtr;

class EndloopCommandNode : public Node {
public: EndloopCommandNode(const NodePtr &target);
public: int type() const;
public: void print(std::ostream &out) const;

public: const std::string & target() const;

};

typedef std::shared_ptr < EndloopCommandNode > EndloopCommandNodePtr;

class ProgramNode : public Node {
public: int type() const;
public: void print(std::ostream &out) const;
};

typedef std::shared_ptr < ProgramNode > ProgramNodePtr;

int number(const NodePtr &p);

const std::string & word(const NodePtr &p);

NodePtr node(int number);

NodePtr node(const std::string &word);

std::ostream &operator<< (std::ostream& out, const NodePtr &p);
