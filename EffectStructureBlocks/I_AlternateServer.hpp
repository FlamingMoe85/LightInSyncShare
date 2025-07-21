#ifndef I_ALTERNATESERVER_HPP
#define I_ALTERNATESERVER_HPP

class I_AlternateServer
{
public:
    virtual bool GetValue(float &_value) = 0;
	virtual void SetValue(float _value) = 0;
};

#endif // I_ALTERNATESERVER_HPP
