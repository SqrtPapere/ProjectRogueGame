

#ifndef Subject_hpp
#define Subject_hpp


#include "Observer.hpp"

class Subject {
protected:
    
    virtual ~Subject() {}
    
public:
    
    virtual void subscribe(Observer* o) = 0;
    
    virtual void unsubscribe(Observer* o) = 0;
    
    virtual void notify() = 0;
};


#endif /* Subject_hpp */
