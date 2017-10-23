
#ifndef Observer_hpp
#define Observer_hpp


class Observer {
    
protected:
    virtual ~Observer() {}
    
public:
    virtual void update() = 0;
    
};

#endif /* Observer_hpp */
