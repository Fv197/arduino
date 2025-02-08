#Elektronisk krets

Arduino operer på 5 volt. Det vil si at er en digital pinne enten er høy eller lav, altså 5V eller 0V. 
Figure 1 viser kretsskjema for den elektroniske kretsen. Fra kretsen så fremkommer det at hvis pinne D13 er høy så lyser LED-en. Hvis bryterene blir trykket inn, så blir pinnene D7 eller D2 koblet til GND og dermed lav.

Kildekode
Vi starter kildekoden med å definere noen variabler:
bool ledState = false;
int BUTTON_PIN1 = 2;
int BUTTON_PIN2 = 7;
int LED_PIN = 13;

bool er forkortelse for boolean, boolsk på norsk, og kan ha to verdier: true eller false.
Int  er forkortelse for integer, heltal på norsk, og kan ha heltall som verdi. f.eks. -6, 0 eller 17
Vi lager altså en bool variabel som heter ledState med verdien false, tre int variabler med navnene BUTTON_PIN1, BUTTON_PIN2 og LED_PIN med verdiene 2, 7 og 13. Disse gjenspeilder pinnene D2, D7 og D13 som vist i Figure 1.

Det neste i kildekoden er funksjonen void setup() som er den første av to obligatiorisk funskjoner ved programmering av Arduino. void setup() kjøres kun en gang ved oppstart av programmet. 

void setup() {
	pinMode(BUTTON_PIN1, INPUT_PULLUP);
	pinMode(BUTTON_PIN2, INPUT_PULLUP);
	pinMode(LED_PIN, OUTPUT);
	digitalWrite(LED_PIN, ledState);
}

pinMode() er en funsjon som spesifiserer om en pinne brukes som inngang eller utgang. Den tar imot to variabler: pin og mode, hvor pin er nummeret på pinnen man setter moden til og mode kan være INPUT, OUTPUT eller INPUT_PULLUP. Hvor INPUT og OUTPUT er selvforklarende så er INPUT_PULLUP en inngang som trekkes til høy av Arduino sin indre krets. Hvis man hadde brukt INPUT med kretsen i Figure 1 så ville man risikert at D2 og D7 hadde blitt tolket som lav uanvhenig av om knappene ble trykket inn eller ikke. 
Vi setter altså BUTTON_PIN1 (2) og BUTTON_PIN2 (7) til INPUT_PULLUP og LED_PIN (13) til OUTPUT.

digitalWrite() er en funsjon som setter en utgang til enten HIGH eller LOW. Den tar imot to variabler: pin og value, hvor pin er nummeret på pinnen man setter verdien til og value er enten HIGH eller LOW.
Vi setter altså pinnen LED_PIN (13) til ledState. ledState har vi allerede definert som false, altså 0 eller LOW. Med andre ord D13 blir 0 volt

Det siste i kildekoden er funksjonen void loop() som er den andre av to obligatoriske funskjoner ved programmering av Arduino. void loop() vil bli repetert så lenge kretsen har spenning.

void loop() {
	if (digitalRead(BUTTON_PIN1) == LOW) {
	ledState = !ledState;
	digitalWrite(LED_PIN, ledState);
	delay(250);
	}
	if (digitalRead(BUTTON_PIN2) == LOW) {
		ledState = !ledState;
		digitalWrite(LED_PIN, ledState);
		delay(250);
	}
}


void loop() inneholder to if funskjoner som er helt like med unntak av hvilken pinne som blir avlest. Vi kan ta det linje for linje:

	if (digitalRead(BUTTON_PIN1) == LOW) {

if setning inneholder en betingelse og et innhold. Betingelsen i denne if setningen er 

	digitalRead(BUTTON_PIN1) == LOW

digitalRead() leser av en port, i dette tilfellet BUTTON_PIN1, altså 2. Den vil være HIGH så lenge knappen ikke er trykket inn, for da blir den LOW. == betyr er lik. 
Betingelsen for if setningen er altså at pinne 13 er lik LOW og da skal innholdet kjøres.

	ledState = !ledState

ledState er en boolsk variabel, og denne setningen endrer den. Med andre ord, var ledState false så blir den true og var den true så blir den false.

	digitalWrite(LED_PIN, ledState);

LED_PIN (13) blir satt til ledState som enten er true eller false, eller HIGH eller LOW.

	delay(250);

Pauser programmet i 0,25 sekund. Dette for at en trykk på knappen skal bli registrert flere ganger.

Neste if setning gjør akkurat det samme bare for  BUTTON_PIN2. Figure 2 hviser en flytskjema for hvordan void loop() fungerer.


