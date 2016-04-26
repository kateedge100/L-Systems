#ifndef LSYSTEMS_H
#define LSYSTEMS_H

#include <iostream>

/// \author Kate Edge
/// \version 1.0
/// \date 26/4/2016
/// \class LSystems
/// \brief Stores contents of txt files

class LSystems
{
public:
    int m_iterations;
    int m_maxIterations;
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
    void selectTree(const int _option);
    const std::string& getDrawingRule() const {return m_str;}
    void createLeaf();


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
