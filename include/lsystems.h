#ifndef LSYSTEMS_H
#define LSYSTEMS_H

#include <iostream>




class LSystems
{
public:
    //Constructor
    LSystems();
    //Destructor
    ~LSystems();
    // Stores Rules
    void productions(int m_iterations);
    //set axiom
    void setAxiom();
    void setAlphabet();
    void setRule();
    void setAlphabetRule();
    void selectTree(int option);
    const std::string& getDrawingRule() const {return m_str;}
    void createLeaf();
    int m_iterations;
    int m_maxIterations;






private:
    void m_clear();
    std::string m_str;
    std::string m_axiom;
    std::string m_alphabet;
    std::string m_axiomRule;
    std::string m_alphabetRule;
    int m_treeOption;

    std::string m_angle;







};

#endif // LSYSTEMS_H
