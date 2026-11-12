#include "./BSP/CAR/li.h"


uint8_t parse_error(const char *s, int8_t *out)
{
	if(s[0]=='E')  
	{
    int sign = 1;
		s++;
    if (*s == '-')
		{ 
			 sign = -1; 
       s++; 
     }
		else if(*s=='+')
		{
			s++;
		 }
    if(*s < '0' || *s > '9')
		{ 
		  return 0;                   
		}
       int v = 0;		
    while (*s>= '0' && *s <= '9')
		{       			        
			  v = v * 10 + (*s - '0');			    
			if(v>=0&&v<=50)
			{
         s++;
			}			 
			else
			{
				 return 0;				
			}       		 
    }
		 if(*s == '\0')
		{
			*out = sign * v;
        return 1;
		}
		else
		{
			  return 0;
		}
       
     }	
	else if(s[0]=='L')
	{
		s++;
		if(*s == '0')
		{
			s++;
			if(*s == '\0')
			{
        *out = 0;
				return 2;
			}
			else
			{
				return 0;
			}	    
		}
		else if(*s == '1')
		{
			s++;
			if(*s == '\0')
			{
        *out = 1;
				return 2;
			}
			else
			{
				return 0;
			}	    
		}		
		else if(*s == '2')
		{
			s++;
			if(*s == '\0')
			{
        *out = 2;
				return 2;
			}
			else
			{
				return 0;
			}
		}			
		else if(*s == '3')
		{
			s++;
			if(*s == '\0')
			{
        *out = 3;
				return 2;
			}
			else
			{
				return 0;
			}	    
		}
		else
		{
		     return 0;
		}		  	
  }
	else 
	{
		return 0;		
	}

}
