#pragma once


class Tools
{
public:
    
    static string toUpperCase ( string str )  
    {  
        string strUpper = "";  
        
        for( int i=0; i<str.length(); i++ )  
        {  
            strUpper += toupper( str[ i ] );  
        }  
        
        return strUpper;  
    } 
    
    
};

