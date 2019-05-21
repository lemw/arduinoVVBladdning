# arduinoVVBladdning

Mitt hybris-projekt för att skriva en liten mjukvara för att ladda en 
varmvattenberedare som är inkopplad på en kulvert med värme.

Tanken är att basera det på:
* en Arduino av enklare slag
* ett reläkort av enklare slag (styrs med IO)
* någon form av shunt alt ventil som kan öppna flödet

Allt detta är för att minimera tiden som kulverten är varm och därmed behöver
användas för att minimera förluster i att värma jorden.

Lite features är att lägga till andra sensorer (inte bara retur och topptemp)
Även inkommande temp på kulvert kan mätas, (detta för att "passa på" att använda
kulverten när en annan konsument av värme på samma kulvert har dragit igång.
(exempel: VVB längst bort vill ladda, då skall även VVB som står mitt emellan
aktivera laddning och toppa upp sitt varmvatten oavsett)
