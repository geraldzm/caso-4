void setup(){
  size(940, 800);
}


void draw(){
  
  
  int pWidth = 250, pHeight =250;
  
  int wRect = (pWidth-10)*28/940; 
  int hRect = pHeight*32/800;
  
  int w =pWidth/wRect, h = pHeight/hRect; // amount of rects  
  
  color black = color(0);
  color white = color(255);
  
  float angle = 0, offset = 0;
  
  for(int row = 0; row < h; ++row) {
        
    offset = sin(angle)*10;
    int yRect = row * hRect;
    for(int column = 0; column < w; ++column) {
      
      int xRect = column * wRect;

      xRect += offset;
      
      fill(column % 2 == 0 ? black: white);
      rect(xRect, yRect, wRect, hRect);      
    }
    
    angle += PI/2;
  }

}
