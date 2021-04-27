void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(9600);
}

String incoming;
String oneSubString;
String toint_conv;
int value;
float values;
float mm = 0.00;
int mode = 0;

bool clear = false;

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial1.available() > 0)
  {
    incoming = Serial1.readString();

    Serial.print("incoming = ");
    Serial.println(incoming);

    oneSubString = incoming;

    Serial.print("oneSubString = ");
    Serial.println(oneSubString);

    if (oneSubString.length() < 3)
    {

      Serial1.print("feet.val=0");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.print("inch.val=0");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.print("mm.val=0");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);

      if (oneSubString.substring(0, 2) == "ft")
      {
        mode = 1;//mode = feet

        Serial1.print("feet.val=1");
      }
      if (oneSubString.substring(0, 2) == "in")
      {
        mode = 2;//mode = inch

        Serial1.print("inch.val=1");
      }
      if (oneSubString.substring(0, 2) == "mm")
      {
        mode = 3;//mode = mm

        Serial1.print("mm.val=1");
      }

      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);

      Serial.print("mode = ");
      Serial.println(mode);

      //clear = true;
    }
    else
    {
      if (oneSubString.substring(0, 4) == "for1")
      {
        if (mode == 1)Serial.println("mode = feet");
        if (mode == 2)Serial.println("mode = inch");
        if (mode == 3)Serial.println("mode = mm");

        Serial.println("forward work");

        Serial1.print("forward.txt=\"Running\"");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.print("forward.val=1");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);

        toint_conv = oneSubString.substring(4);
        value = toint_conv.toInt();
        values = value;
      }
      else if (oneSubString.substring(0, 5) == "back1")
      {
        if (mode == 1)Serial.println("mode = feet");
        if (mode == 2)Serial.println("mode = inch");
        if (mode == 3)Serial.println("mode = mm");

        Serial.println("backward work");

        Serial1.print("backward.txt=\"Running\"");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.print("backward.val=1");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);

        toint_conv = oneSubString.substring(5);
        value = toint_conv.toInt();
        values = value;
      }



      if (mode == 1) {
        mm = values * 304.80 / 10.00;
      }
      else if (mode == 2) {
        mm = values * 25.40 / 10.00;
      }
      else if (mode == 3) {
        mm = values / 10.00;
      }

      Serial.print("move in mm = ");
      Serial.println(mm);

      Serial1.print("forward.val=0");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.print("forward.txt=\"Forward\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.print("backward.val=0");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.print("backward.txt=\"Backward\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);

      //clear = true;
    }
  }
  if (clear == true)
  {
    //clear string for new incoming data
    for (int i = 0; incoming.length(); i++)
    {
      incoming[i] = NULL;
    }
    for (int i = 0; oneSubString.length(); i++)
    {
      oneSubString[i] = NULL;
    }
    for (int i = 0; toint_conv.length(); i++)
    {
      toint_conv[i] = NULL;
    }
    value = 0;
    values = 0;
    mm = 0;

    clear = false;
  }
}
