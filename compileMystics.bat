@g++ src/Arrow.cpp src/Diamonds.cpp src/TextDraw.cpp src/Main.cpp -L/lib -L/lib -L/lib -lglut32 -lglu32 -lopengl32 -o bin/Mental_Mystics.exe

@if ERRORLEVEL == 1 ( 
  echo You failed... 
) else (echo Success.)

@pause