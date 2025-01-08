//Morse code Encoder and transmitter (07-01-2025)

//Dit: 1 unit, Dah: 3 units
//Intra-character space (the gap between dits and dahs within a character): 1 unit
//Inter-character space (the gap between the characters of a word): 3 units
//The gap between two words: 7 units
//NOTE: for adjusting the "words per minute" (speed), vary the unitTime according to the speed of transmission of morse code message

#define unitTime 60 //60 millisec gap between each dit and dah for 20wpm speed
int i,len;
char ch;
String str;
const int buzzerDigPin=3;
void morse(char);
void dit();
void dah();

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
  Serial.print("\nPlease Enter Your Message to communicate through encryption\n");
  Serial.print("Morse Code Encoder & Transmitter | speed: 20wpm\n\n");
  while(Serial.available()==0){
    
  }
  str=Serial.readString();
  len= str.length();
  Serial.print("Your encrypted Message is :\n");
  for(i=0;i<len;i++){
    ch=str.charAt(i);
    if(ch==' '){
      Serial.print("/");//For space between each word in the string
      delay(unitTime*7-240); //Time delay between two words in the string
    }
    else{
      morse(ch);
      Serial.print(" ");
    }
  }
  Serial.print("\nMessage delivered\n\n");
}

void morse(char ch){
  switch (ch){
    case 'A':
    case 'a':
      dit();
      dah();
      delay(unitTime*3);
      break;
    case 'B':
    case 'b':
      dah();
      dit();
      dit();
      dit();
      delay(unitTime*3);
      break;
    case 'C':
    case 'c':
      dah();
      dit();
      dah();
      dit();
      delay(unitTime*3);
      break;
    case 'D':
    case 'd':
      dah();
      dit();
      dit();
      delay(unitTime*3);
      break;
    case 'E':
    case 'e':
      dit();
      delay(unitTime*3);
      break;
    case 'F':
    case 'f':
      dit();
      dit();
      dah();
      dit();
      delay(unitTime*3);
      break;
    case 'G':
    case 'g':
      dah();
      dah();
      dit();
      delay(unitTime*3);
      break;
    case 'H':
    case 'h':
      dit();
      dit();
      dit();
      dit();
      delay(unitTime*3);
      break;
    case 'I':
    case 'i':
      dit();
      dit();
      delay(unitTime*3);
      break;
    case 'J':
    case 'j':
      dit();
      dah();
      dah();
      dah();
      delay(unitTime*3);
      break;
    case 'K':
    case 'k':
      dah();
      dit();
      dah();
      delay(unitTime*3);
      break;
    case 'L':
    case 'l':
      dit();
      dah();
      dit();
      dit();
      delay(unitTime*3);
      break;
    case 'M':
    case 'm':
      dah();
      dah();
      delay(unitTime*3);
      break;
    case 'N':
    case 'n':
      dah();
      dit();
      delay(unitTime*3);
      break;
    case 'O':
    case 'o':
      dah();
      dah();
      dah();
      delay(unitTime*3);
      break;
    case 'P':
    case 'p':
      dit();
      dah();
      dah();
      dit();
      delay(unitTime*3);
      break;
    case 'Q':
    case 'q':
      dah();
      dah();
      dit();
      dah();
      delay(unitTime*3);
      break;
    case 'R':
    case 'r':
      dit();
      dah();
      dit();
      delay(unitTime*3);
      break;
    case 'S':
    case 's':
      dit();
      dit();
      dit();
      delay(unitTime*3);
      break;
    case 'T':
    case 't':
      dah();
      delay(unitTime*3);
      break;
    case 'U':
    case 'u':
      dit();
      dit();
      dah();
      delay(unitTime*3);
      break;
    case 'V':
    case 'v':
      dit();
      dit();
      dit();
      dah();
      delay(unitTime*3);
      break;  
    case 'W':
    case 'w':
      dit();
      dah();
      dah();
      delay(unitTime*3);
      break; 
    case 'X':
    case 'x':
      dah();
      dit();
      dit();
      dah();
      delay(unitTime*3);
      break;
    case 'Y':
    case 'y':
      dah();
      dit();
      dah();
      dah();
      delay(unitTime*3);
      break; 
    case 'Z':
    case 'z':
      dah();
      dah();
      dit();
      dit();
      delay(unitTime*3);
      break;
    case '1':
      dit();
      dah();
      dah();
      dah();
      dah();
      delay(unitTime*3);
      break;
    case '2':
      dit();
      dit();
      dah();
      dah();
      dah();
      delay(unitTime*3);
      break;
    case '3':
      dit();
      dit();
      dit();
      dah();
      dah();
      delay(unitTime*3);
      break;
    case '4':
      dit();
      dit();
      dit();
      dit();
      dah();
      delay(unitTime*3);
      break;
    case '5':
      dit();
      dit();
      dit();
      dit();
      dit();
      delay(unitTime*3);
      break;
    case '6':
      dah();
      dit();
      dit();
      dit();
      dit();
      delay(unitTime*3);
      break;
    case '7':
      dah();
      dah();
      dit();
      dit();
      dit();
      delay(unitTime*3);
      break;
    case '8':
      dah();
      dah();
      dah();
      dit();
      dit();
      delay(unitTime*3);
      break;
    case '9':
      dah();
      dah();
      dah();
      dah();
      dit();
      delay(unitTime*3);
      break;
    case '0':
      dah();
      dah();
      dah();
      dah();
      dah();
      delay(unitTime*3);
      break;
  }
}
//Function for dit
void dit(){
  tone(buzzerDigPin,700,unitTime);
  delay(unitTime);
  noTone(buzzerDigPin);
  delay(unitTime);
  Serial.print(".");
}
//Function for dah
void dah(){
  tone(buzzerDigPin,700,unitTime*3);
  delay(unitTime);
  noTone(buzzerDigPin);
  delay(unitTime);
  Serial.print("-");
}