#ifndef MLX90393_h
#define MLX90393_h

class MLX90393 {
  public:
    MLX90393(unsigned char Addr);
    void Read();
    int x; 
    int y; 
    int z;
  private:
    unsigned char Addr;
    unsigned int c ;
    int once;
    int startTime;
    int first_xMag;
    int first_yMag;
    int first_zMag;
};

#endif