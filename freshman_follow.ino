const int IN_A1=5;
const int IN_A2=4;
const int IN_B1=3;
const int IN_B2=2;
const int sensor1_num=8;
const int sensor2_num=9;
const int sensor3_num=10;
const int sensor4_num=11;
const int sensor1=0;
const int sensor2=0;
const int sensor3=0;
const int sensor4=0;

const int cnt_l = 0;
const int cnt_r = 0;


void setup()
{
  pinMode(IN_A1,OUTPUT);
  pinMode(IN_A2,OUTPUT);
  pinMode(IN_B1,OUTPUT);
  pinMode(IN_B2,OUTPUT);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT); 
  pinMode(sensor4,INPUT); 
}

void fwd()//直行
{
  if(sensor1==1&&sensor2==1&&sensor3==1&&sensor4==1)
  {
     analogWrite(IN_A1,200);
     analogWrite(IN_A2,0);
     analogWrite(IN_B1,200);
     analogWrite(IN_B2,0);
     delay(300);
  }
  
  while(sensor1==0 && sensor4==0)
  {

     if(sensor3==1&&sensor1==0)
     {
     analogWrite(IN_A1,170);
     analogWrite(IN_A2,0);
     analogWrite(IN_B1,200);
     analogWrite(IN_B2,0);
      }
    else if(sensor2==1&&sensor1==0)
    {
     analogWrite(IN_A1,200);
     analogWrite(IN_A2,0);
     analogWrite(IN_B1,170);
     analogWrite(IN_B2,0);
    }  
    else
    {
     analogWrite(IN_A1,200);
     analogWrite(IN_A2,0);
     analogWrite(IN_B1,200);
     analogWrite(IN_B2,0);      
    }
   }
}
void turnleft()//左转
{
     analogWrite(IN_A1,100);
     analogWrite(IN_A2,0);
     analogWrite(IN_B1,200);
     analogWrite(IN_B2,0);
     delay(1000);//此延时须自行调到刚好转90度
}
void turnright()//右转
{
     analogWrite(IN_A1,200);
     analogWrite(IN_A2,0);
     analogWrite(IN_B1,100);
     analogWrite(IN_B2,0);
     delay(1000);//此延时须自行调到刚好转90度
}
void loop()
{
  sensor1=digitalRead(sensor1_num);
  sensor2=digitalRead(sensor1_num);
  sensor3=digitalRead(sensor1_num);
  sensor4=digitalRead(sensor1_num);

  fwd();
  
  if(sensor1==1 && sensor2==1 && cnt_r!=1)
  {
  turnright();
  cnt_r++;  
  }

  if(sensor3==1 && sensor4==1 && (cnt_l==0 || cnt_l==2))
  {
  turnleft();
  cnt_l++; 
  }
  }

