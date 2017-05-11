
#ifndef API_Interface_h
#define API_Interface_h

class APIInterface{
public:
    int Connect();
    int Disconnect();
    int SendMessage();
    
private:
    int CheckSessionStatus();
    
};


#endif /* API_Interface_h */
