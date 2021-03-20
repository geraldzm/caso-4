color black = color(0), white = color(255);
int widthSquare, heightSquare;
Square [] squares;


Square[] convertString(String pCppString) {
  
  String [] splitted = pCppString.split(";");
  
  widthSquare = parseInt(splitted[0].split(",")[0]);
  heightSquare = parseInt(splitted[0].split(",")[1]);
  
  Square[] list = new Square[splitted.length-1]; 
  
  for(int i = 1; i < splitted.length; i++) {
    String[] squareData = splitted[i].split(",");    
    list[i-1] = new Square(parseInt(squareData[0]), parseInt(squareData[1]), parseBoolean(parseInt(squareData[2])));
  }
   
  return list;
}

void setup() {
  size(940, 800);
  squares = convertString("");  
}

void draw() {
  for(Square square: squares) { 
      fill(square.rectColor ? white: black);
      rect(square.x, square.y, widthSquare, heightSquare);      
  }
}
