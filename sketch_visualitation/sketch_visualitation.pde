void setup(){
  size(940, 800);
}


void draw(){

  int w = 11, h = 10; // amount of rects
  int wRect = width / (w* 2);
  int hRect = height / (h*2);
  
  
  color black = color(0);
  color white = color(255);
  


  
  float angle = 0, offset = 0;
  
  
  for(int row = 0; row < h; ++row) {
    
    
    offset = sin(angle)*10;
    for(int column = 0; column < w; ++column) {
      
      int xRect = column * wRect;
      int yRect = row * hRect;
      
      xRect += offset;
      
      fill(column % 2 == 0 ? black: white);
      rect(xRect, yRect, wRect, hRect);      
    }
    
    angle += PI/2;
  }



}
