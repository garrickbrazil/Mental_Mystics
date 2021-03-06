@if not exist bin\ (
	@mkdir bin
)

@g++ src/SquareSpiral.cpp src/MissingPeg.cpp src/DisappearingGrad.cpp src/Circle.cpp src/Arrow.cpp src/Checker.cpp src/BlackDots.cpp src/LinesAndCircle.cpp src/TextDraw.cpp src/Main.cpp glut32.lib -L/lib -L/lib -L/lib -lglut32 -lglu32 -lopengl32 -o bin/Mental_Mystics.exe

@if ERRORLEVEL == 1 ( 
  echo You failed... 
  @pause
) else ( 
  echo Success. 
  @cd bin
  @Mental_Mystics.exe 
)


