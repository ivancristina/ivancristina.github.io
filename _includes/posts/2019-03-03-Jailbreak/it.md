> *If you wanna read the guide in English, just click on the selector right up here*

# Introduzione

Ecco una guida completa su come eseguire il jailbreak da iOS **11** fino a **12.1.2**. Tutte le versioni intermedie sono compatibili, tranne in alcune configurazioni.
Questa guida è specifica a queste versioni di iOS. Tutte le versioni precedenti sono jailbreakable, ma le versioni successive devono ancora essere exploitate.
Al momento, i device con Apple **A12** (iPhone XS, XS Max, XR and iPad Pro 2018) sono **parzialmente** exploitabili a causa di alcune protezioni di sicurezza di Apple come la *PAC*, o *Pointer Autenthication*. Se vuoi saperne di più, scriverò un post più specifico in futuro. Ma se sei qui per questa guida, probabilmente rimarrai qui.

### Requisiti

Per eseguire il jailbreak hai bisogno di pochi ma importanti requisiti:
* Un Apple **iPhone** (5S o successivo), **iPad** (Air/Mini 2 o successivo) or **iPod** (6 generazione o seguente)
* Una versione di iOS successiva a **11**, ma inferiore a **12.1.2** - ***è fondamentale***
* Accesso a internet
* Tempo, pazienza e conoscenze informatiche basilari

## Preparazione

* Prima di tutto ricorda che (nonostante sia davvero stabile) questa è una **versione beta**, usala con cautela o aspetta per la versione finale se sei troppo inesperto
* Assicurati che su Impostazioni → Generali → Spazio Libero non ci sia alcun **aggiornamento OTA** (apparirà come *iOS 12.x*): in caso ce ne sia uno, eliminalo prima di inizia il processo di jailbreaking
![alt text](/img/Jailbreak/iStorage.png "Check for the OTA in here")
* In modo da bloccare definitivamente gli aggiornamenti OTA installa il *profilo tvOS* [clicccando](https://raw.githubusercontent.com/Jwhite077/NOOTA/master/tvOS_12_Beta_Profile.mobileconfig). Il tuo dispositivo richiederà il tuo codice di sblocco ed in seguito si riavvierà. Appena hai riavviato, gli aggiornamenti spariranno fin quando non rimuoverai il profilo. Nella schermata "aggiornamenti di sistema" otterrai infatti questo errore
![alt text](/img/Jailbreak/tvOS.png "Install the tvOS profile")
* Se hai già usato **rootlessJB** su iOS 12, disinstallalo cliccando sul tasto “Uninstall” all'interno del tool

## Download

Ci sono due modi per installare unc0ver. Puoi installarlo sia da PC tramite un tool chiamato **Cydia Impatactor**, sia tramite store di terze parti. In questa guida però, illustrerò un metodo ancora più semplice per gli utenti italiani.

#### @JailbreakItalia

Il gruppo Telegram di Jailbreak Italia offre (oltre ad un incredibile supporto utenti) un bot che permette tramite pochi semplici passi di installare l'ultima versione di unc0ver in maniera completamente gratuita, rapida ed intuitiva.
Scaricate (se non lo avete già fatto - e sarebbe un errore) [Telegram](https://itunes.apple.com/it/app/telegram-messenger/id686449807?l=en&mt=8). Per i pochi che non dovessero conoscerlo, è l'alternativa *open-source*, sicura, versatile e leggera a WhatsApp. Telegram permette però - oltre a tantissime altre funzioni davvero innovative - di accedere a gruppi, supergruppi e canali. La community italiana ha infatti scelto il supergruppo **Jailbreak Italia** come centro di ritrovo e di supporto per gli appassionati del Jailbreak.
Per entrare nel gruppo, basta [cliccare qui](https://t.me/JailbreakItalia).
Una volta visionate le regole - ed eventualmente salutare *:P* - basta scrivere "**!uncoverdl**" (senza virgolette) ed inviare il messaggio. Un bot vi risponderà automaticamente chiedendo quale versione volete installare. Selezionate **unc0ver Beta**, visionate le avvertenze e all'apparizione di un popup di conferma per l'installazione, date il consenso.
Prima di aprire l'app avrete bisogno di un'ultima cosa: recatevi su Impostazioni → Generali → Profili, aprite il profilo aziendale che apparirà (usato per firmare l'app) e cliccate su *Verifica*.
![alt text](/img/Jailbreak/Profiles.png "Trust the profile")

L'app sarà ormai verificata e potrai aprirla.
![alt text](/img/Jailbreak/unc0ver Icon.png "You can now open unc0ver")

## Jailbreaking

Una volta aperto unc0ver vai nella tab *Settings* ed assicurati di avere le configurazioni di default. Nel momento in cui sto scrivendo il post, sono queste.
![alt text](/img/Jailbreak/unc0ver Settings.png "Leave everything as it is")

Ok, ora torna alla home screen di unc0ver. Vedrai un grande bottone con su scritto **Jailbreak**. Quando sei pronto, cliccaci su. Ogni volta che lo farai, il processo terminerà con un riavvio o un respring: ne parlerò in seguito.
![alt text](/img/Jailbreak/unc0ver.png "Press the Jailbreak button")

Adesso, cliccalo. Il dispositivo eseguirà l'exploit e se questo andrà a buon fine avrai raggiunto il primo di tre passaggi, lo **snapshot renaming"**. Premi *OK* ed il dispositivo si riavvierà.
![alt text](/img/Jailbreak/Snapshot Rename.png "First step done")

Potrebbe succedere che allo step **2/38** il dispositivo potrebbe andare in *panic* poiché l'exploit potrebbe fallire ed il dispositivo si riavvierà automaticamente. Non ti preoccupare, può succedere, aspetta che il dispositivo si riavvii, quindi riprova.
![alt text](/img/Jailbreak/unc0ver Exploit.png "The device could panic at step 2/38")

Di nuovo, apri unc0ver e clicca il pulsante Jailbreak. Se tutto va bene, eseguirai la **bootstrap extraction**. Premi OK ed attendi il riavvio.
![alt text](/img/Jailbreak/Bootstrap Extracted.png "First step done")

Ora dovrebbe essere l'ultima volta: premi il pulsante Jailbreak. Ad un certo punto il device eseguirà un **respring**: lo schermo diventerà nero e diminuirà la luminosità, al centro dello schermo apparirà una rotella che gira (come quando il dispositivo si spegne). Attendi che finisca e potrai finalmente vedere installata **Cydia**!
![alt text](/img/Jailbreak/Cydia Icon.png "Cydia appeared")

Ora il jailbreak è attivato, ma ricorda che questo è jailbreak è ***semi-unthetered***. Ciò significa che ogni qualvolta riavvierai il device, questo tornerà in modalità jailed. Ma non è un grosso problema: apri unc0ver, premi il pulsante *Jailbreak* e dopo un respring il dispositivo si riavvierà nuovamente.

Ricorda di aggiornare l'app di unc0ver dal gruppo Telegram ogni tanto, in modo da avere l'esperienza più stabile possibile! Quando avrai aggiornato l'app, premi il pulsante *Re-Jailbreak*.
![alt text](/img/Jailbreak/unc0ver ReJailbreak.png "Press the Re-Jailbreak button")

## Configurare Cydia

Ora è tempo di configurare Cydia. Prima di tutto aprila e verrai accolto dalla schermata di benvenuto.
![alt text](/img/Jailbreak/Cydia.png "Welcome")

vai nella sezione *Sorgenti* in basso, e vedrai questa schermata.
![alt text](/img/Jailbreak/Cydia Sources.png "Sources tab")

Quelle che vedi sono le **repositories**, dove tutti i **tweaks** sono contenuti e da dove vengono distribuiti. La maggior parte dei tweaks sono gratuiti, ma alcuni sono a pagamento. ***NON PIRATARLI***, per diverse ragioni. Prima di tutto, perché gli sviluppatori impiegano molto del loro tempo per offrirci questi ottimi lavori, che probabilmente non avremmo mai senza supportarli ripagandoli almeno del tempo impiegato nello scriverli. Secondo, perché i tweak piratati possono in alcuni casi portare a **bootloops**, forzandovi a ripristinare il vostro dispositivo, perdendo così sia il jailbreak che ***tutti*** **i vostri dati**. Scaricali sempre i tweak dalle loro repo ufficiali (solitamente sono *BigBoss*, *Chariz* o *Dynastic*). Se non sei certo della repo del tweak che stai cercando, cerca su Google "`nome del tweak qui` repo". La troverai sicuramente.

Ogni qualvolta premerai *Aggiorna* le sorgenti si aggiorneranno ed un pallino rosso apparirà. Facendo così aggiornerai l'*indice* delle sorgenti e nel caso in cui ci siano aggiornamenti dei tweak disponibili, questi appariranno. Solitamente è meglio aggiornare i tuoi tweak in modo da migliorarne la stabilità. Se qualunque *Aggiornamento indispensabile* apparirà, performa un *Aggiornamento completo*. Questi pacchetti sono aggiornati dal maintainer del tuo jailbreak in modo da renderlo più stabile.
![alt text](/img/Jailbreak/Cydia Necessary Update.png "Perform a complete update")

Ma come aggiungere una repo? È molto semplice. La maggior parte delle repo hanno un pulsante specifico nel loro sito web che apre una finestra per aggiungere automaticamente la repo, ma potrebbe succedere che tu debba aggiungerla manualmente. In quel caso premi il tasto *Modifica* in alto a destra, quindi *Aggiungi* e copia l'URL della repo, quindi *Aggiungi sorgente*. In questo caso aggiungerò `http://tigisoftware.com/cydia`, la repo di **Filza**. Ne parleremo in seguito.
![alt text](/img/Jailbreak/Cydia Sources Add.png "Add the source")

Se vuoi cancellare una repo, semplicemnte premi *Modifica*, quindi rimuovila con il tasto rosso al suo fianco.
![alt text](/img/Jailbreak/Cydia Sources Remove.png "Remove source in this way")

### Installare i tweaks

Ora arriva la parte divertente: installare i tweaks. I tweaks sono pacchetti che personalizzano il tuo sistema, aggiungendo funzioni o addirittura anche apps. In questo esempio installeremo una famosa app jailbroken chiamata **Filza**. È un gestore file con privilegi ***root***. Se sei inesperto non usarla, ma è sempre meglio averla installata.

In Cydia, aggiorna le sorgenti, quindi vai su *Cerca* e digita il nome del pacchetto che ti interessa. Ci sarà più di un risultato, in questo caso seleziona la versione **64bit** (considerato il fatto che stai usando unc0ver, il tuo hardware deve essere a 64bit).
![alt text](/img/Jailbreak/Cydia Search Filza.png "Search for the packages here")

Una finestra popupsi aprirà. Se vuoi installare altro premi *Continua a mettere in coda*, altrimenti *Conferma*.
![alt text](/img/Jailbreak/Cydia Installation Confirm.png "Press confirm to install")

Vedrai un **verbose** output di quello che sta succedendo.
![alt text](/img/Jailbreak/Cydia Filza Installation.png "Verbose output")

Quando leggerai *Riavvia SpringBoard* premilo. Dopo un respring vedrai in azione i tuoi nuovi tweak o le app!
![alt text](/img/Jailbreak/Cydia Restart SpingBoard.png "Press Restart SpringBoard")

Ed ora infatti dovresti vedere Filza installato.
![alt text](/img/Jailbreak/Filza Icon.png "Here it is")

Se vuoi rimuovere un tweak che hai installato, vai nella sezione *Installato*, apri il tweak che vuoi rimuovere, clicca su *Modifica* e quindi *Rimuovi*. Anche in questo caso puoi mettere in coda altri processi.
![alt text](/img/Jailbreak/Cydia Installed.png "This is the Installed tab")

Come ho detto i tweak possono modificare vari aspetti di iOS, in questo caso puoi vedere le impostazioni di sistema prima e dopo l'installazione del tweak **System Info**.
![alt text](/img/Jailbreak/iOS Info.png "Before")
![alt text](/img/Jailbreak/iOS Info Tweak.png "After")

Infine, controlla periodicamente gli aggiornamenti aggiornando le sorgenti. Se ce ne saranno, verranno mostrati nella sezione *Novità*.
![alt text](/img/Jailbreak/Cydia Changes.png "Updates will show up here")

### Fine

Adesso sei pronto a ~~distruggere~~ sperimentare con il tuo dispositivo.

Puoi trovare i miei social in fondo alla pagina, in caso tu voglia seguirmi o abbia bisogno di aiuto urgente. Se hai qualche domanda, ricorda che puoi sempre chiedere aiuto nel gruppo **Jailbreak Italia**.

> Buon Jailbreak!
> Ivan
