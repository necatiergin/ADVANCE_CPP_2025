struct Nec {};

Nec nec;
const Nec cnec;

/*
                        PARAMS FOR OVERLOADS

argument                Nec&      const Nec&       Nec&&      const Nec&&
===========             =====     ==========       =====      ===========
nec                        1           2             X             X               
cnec                       X           1             X             X
Nec{}                      X           3             1             2
std::move(cnec)            X           2             X             1     

*/
