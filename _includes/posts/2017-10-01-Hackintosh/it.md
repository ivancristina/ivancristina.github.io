> _If you wanna read the guide in English, just click on the selector right up here_

Non è stato per niente facile, ma ne è valsa la pena! Un Hackintosh (quasi) completamente funzionante!

La seguente guida non è raccomandata ai nabbi (nonostante ne sia uno io stesso), a meno che non tu voglia perdere un sacco di tempo anche solo per riuscire ad effettuare il primo avvio, ma ti assicuro che il risultato vale tutti i mal di testa che ti verranno dopo!

# 1. La mia build

Cominciamo con la mia build. L'ho assemblata circa 7 mesi fa, e mi è costata qualcosa tipo €500. Adesso potrebbe costare anche 100 euro in meno, ma sono comunque felice del risultato ottenuto con quel budget.

Il mio intero setup comprende:

-   una  **[MSI H270 Gaming M3](http://amzn.eu/h3i8nZy)**, una mobo serie 200, con una striscia di LED rossi a lato ed una bella estetica dopotutto. Vale i €126 spesi, ora €116\*.
-   un **[Intel Core i5-7500](http://amzn.eu/5WilklT)**, un Kaby Lake a 3.4Ghz con 6Mb di cache. Comprato a €211, ora a €184\*
-   un **[Western Digital Blue](http://amzn.eu/1DicCyw)** 1 Tb a 7200RPM HDD. Davvero solido. Ottimo prodotto per i 51 euro che mi è costato\* (prezzo che ha mantenuto).
-   un singolo slot di RAM **[Ballistix Sport LT](http://amzn.eu/j4PcU9x)**. 8 Gb DDR4 a 2400Mhz di clock. Buon affare per €54, considerato che ora costa più di €10 in più.
-   un PSU **[Corsair VS450](http://amzn.eu/7L74v01)**, certificazione 80+ ed ottima qualità a €41\*. Comprato per via di un non pianificato acquisto di una GPU, ora **me ne pento un po'**, ad essere sincero.
-   ed infine, il **[Carbide Spec-03](http://amzn.eu/6XEPdiw)**. Stupendo case ATX, con un bel pannello laterale in plastica, dotato di due silenziosissime ventole Corsair (una LED e l'altra no). Ha mantenuto il suo prezzo di €65.

> _I prezzi sono riferiti a quelli su Amazon.it nel Marzo 2017_

Ma potresti chiederti.. perché non un alimentatore più potente? Perché non una scheda video dedicata a posto di quella mer$!osa HD 630? O ancora, perché non un dannato SSD?
Beh, sono stato stupido. Un **povero stupido**. Non pensavo e non avevo soldi. Soprattutto in questi mesi, assieme al prezzo delle GPU di fascia alta per il bitcoin mining _(grazie cari, vi auguro di perdere tutti i bitcoin che avete minato finora)_, gli shop italiani, sia fisici che virtuali (come Amazon), hanno pensato bene di alzare i prezzi. Di tutto! Anche CPU, GPU di fascia bassa ed SSD. Quest'ultimi in particolare costano **circa il doppio** del loro prezzo "reale".

Per quanto concerne la scheda madre, **assolutamente degna di nota**. Serie H perché non avevo bisogno delle features della Z, ed anche perché in veste di (povero) studente, non posso permettermi nè una mobo di serie Z nè una CPU serie K (con moltiplicatore sbloccato). In ogni caso, bella da vedere, ben costruita ed ottimamente gestita dai software MSI su Windows. Su Hackintosh... si sà, nuovo non sempre significa migliore, specialmente se in pratica stai adattando un OS closed source su hardware non proprietario. Ma alcune patch, e tutto è a posto.

La CPU... DANNAZIONE, se **l'ho odiata!** Voglio dire, è efficiente energeticamente ed abbastanza prestante, ma il prezzo era un po' troppo alto per il prodotto _IMHO_. E come ho detto prima... È stata davvero un'ammazzata farla funzionare su Sierra, fino all'arrivo della nuova serie Mac 2017, assieme ai suoi nuovi modelli Kaby Lake. Ciò rese tutto  **MOLTO PIÙ SEMPLICE**. Infatti, prima dell'update a 10.12.6 (con relativo supporto kernel ai modelli Kaby Lake), per fare funzionare Hackintosh su un Kaby Lake era necessario effettuare uno [spoofing di CPU e GPU ID](https://www.tonymacx86.com/threads/new-testing-intel-7th-generation-kaby-lake-cpus-200-series-motherboards-in-macos.219877/), ed a volte nemmeno questo risolveva molto (come nel mio caso .-.). Far funzionare la GPU con la piena accelerazione è stato un casino, ma alla fine a posto dei fo$!uti 7mb di nvram virtualizzata, sono riuscito a far andare la GPU con tutti i suoi 1536 MB di memoria. E solo dopo, grazie all'update 10.12.6, sono anche riuscito a far funzionare la CPU alla massima potenza.

![java-javascript](/img/Hackintosh/Info.png)

Le seguenti patches (necessarie su 10.12.5 o antecedente per far funzionare CPU e Grafica Integrata) non sono infatti più necessarie su Sierra 10.12.6 o in ogni versione della nuova versione di Apple macOS, [High Sierra!](https://www.tonymacx86.com/threads/macos-high-sierra-is-now-available-on-the-mac-app-store.231773/) _(che fantasia, però...)_

```html
<key>FakeID</key>
<dict>
	<key>IntelGFX</key>
	<string>0x19168086</string>
```

```html
<key>Devices</key>
<dict>
	<key>AddProperties</key>
	<array>
		<dict>
			<key>Device</key>
			<string>IntelGFX</string>
			<key>Key</key>
			<string>AAPL,GfxYTile</string>
			<key>Value</key>
			<data>
			AQAAAA==
			</data>
		</dict>
	</array>
```

Puoi trovare il mio [config.plist completo qui](https://github.com/ivancristina/ivancristina.github.io/raw/master/resources/config.plist).

## 2. Configurazioni BIOS

Potrebbero variare in base alla scheda madre.

-   **Step 1:** Load Optimised Default
-   **Step 2:** Sulla BIOS Tab
    		Windows 8/10 Features = Other OS
    		Storage Boot Option Control = UEFI
-   **Step 3:** Peripherals Tab
    		Initial Display Output = IGFX
    		XHCI Handoff = Enabled (In USB Configuration)
-   **Step 4:** Chipset Tab
    		VT-D = Disabled
    		Internal Graphics = Enabled
    		DVMT Pre-Allocated = 64M
-   **Step 5:** Save and Exit

### 3. Cosa scaricare

Hai bisogno di scaricare diversi file per funzionare tutto. Questi file sono necessari durante tutta la sessione di installazione di Mac OS.

##### 3.1. Bootloader

L'ultima versione di [Clover Bootloader](https://sourceforge.net/projects/cloverefiboot/). Questo Bootloader permette di avviare sia MacOS, che Windows e distro Linux, tutte in uno e con una interfaccia altamente personalizzabile.

##### 3.2. Utilità

Sono apps o scripts che ti aiuteranno durante l'inizializzazione, installazione e configurazione di Hackintosh. Scarica le ultime versione in base alla tua versione di macOS

-   [Clover Configurator](http://mackie100projects.altervista.org/download-clover-configurator/). Se dovessi riscontrare il **bug dei 7mb** usa la versione Classic a posto della Vibrant. Quest'app ti permette di configurare le tue impostazioni bootloader tramite un'accattivamente UI, invece che tramite riga di comando (disponibile pure)
-   [UniBeast, MultiBeast and KextBeast](https://www.tonymacx86.com/resources/categories/tonymacx86-downloads.3).
    Queste apps ti permettono rispettivamente di creare una USB avviabile, configurare la tua Hackintosh machine ed installare alcuni drivers primari in **post-installazione**
-   [audio_cloverHDMI-130.command](https://github.com/toleda/audio_CloverHDMI/blob/master/audio_cloverHDMI-130.command.zip?raw=true) di [Toleda](https://github.com/toleda/). Questo script permette in pochi click di abilitare l'**audio onboard** della HD630.

##### 3.3. Kexts

I kexts sono praticamente drivers, che permettono di usare le varie periferiche nel modo più _plug&play_ possibile.

-   [AppleALC.kext](https://github.com/vit9696/AppleALC/releases) di [vit9696](https://github.com/vit9696) - repo Github [qui](https://github.com/vit9696/AppleALC)
-   [Lilu.kext](https://github.com/vit9696/Lilu/releases) di [vit9696](https://github.com/vit9696) - repo Github [qui](https://github.com/vit9696/Lilu)
-   [Shiki.kext](https://github.com/vit9696/Shiki/releases) di [vit9696](https://github.com/vit9696) - repo Github [qui](https://github.com/vit9696/Shiki)
-   [XHCI-200-series-injector.kext](https://github.com/RehabMan/OS-X-USB-Inject-All/tree/master/XHCI-200-series-injector.kext) di [RehabMan](https://github.com/RehabMan) - repo Github [qui](https://github.com/RehabMan/OS-X-USB-Inject-All)
-   [USBInjectAll.kext](https://bitbucket.org/RehabMan/os-x-usb-inject-all/downloads/) di [RehabMan](https://github.com/RehabMan) - repo Bitbucket [qui](https://bitbucket.org/RehabMan/os-x-usb-inject-all/src)

Altri kexts di cui avrai bisogno in seguito: _(in post installazione, tramite MultiBeast)_

-   AtherosE2200Ethernet.kext
-   FakeSMC.kext
-   IntelMausiEthernet.kext
-   RealtekRTL8111.kext

## 4. Installazione

##### 4.1. Prerequisiti

-   Una **Mobo Serie 200** con Processore Intel di 7<sup>a</sup> Generazione _(KabyLake)_
-   Un Mac, Hackintosh o Macchina Virtuale **_funzionante_** (sebbene le VM non siano raccomandate) - senza uno di questi non puoi proseguire.
-   Una chiavetta USB da **16GB** o più (alcuni riportano di essere riusciti a far funzionare il tutto con una da 8GB, sebbene non sia il mio caso)

##### 4.2. Scaricare macOS

1.  Sul tuo Mac, Hackintosh o VM apri il Mac App Store
2.  Accedi con il tuo Apple ID
3.  Scarica macOS Sierra (10.12.6) o High Sierra _- questa guida è basata su 10.12.6, ma potrebbe essere applicabile anche su High Sierra con qualche dovuta modifica_
4.  Al termine del download il setup dovrebbe avviarsi e dovresti premere **Esci** tramite tasto destro sull'icona del Dock. Puoi trovare l'app del setup in **/Applicazioni/Install MacOS Sierra.app**

##### 4.3. Preparare la USB

**_Se la seguente guida non funziona nel tuo caso prova invece [con questa](https://www.tonymacx86.com/threads/updated-for-multibeast-9-2-1-and-sierra-10-12-6-sierra-on-200-series-with-kabylake-processor.218494/page-12#post-1586314)_**

1.  Apri Utility Disco –> Seleziona la USB ed Inizializzala usando **Mac OS esteso (journaled)** –> **Mappa partizione GUID** –> **Inizializza**
2.  Ora apri Unibeast –> Scegli la USB –> Quindi seleziona **UEFI** –> Dopodichè seleziona Sierra
3.  Apri la partizione EFI della USB –> EFI/Clover –> Apri il config.plist tramite Clover Configurator
4.  Esegui le modifiche necessarie (nessuna nel mio caso)

Nel caso tua abbia un build molto simile alla mia, rinomina l'esistente **conf.plist** in **orig-config.plist** ed incollagli il mio.

**_Sposta TUTTI i file scaricati nella USB, crea una cartella ed incollali lì._**

##### 4.4. Tweak porte USB

> _Non necessario se usi il mio config.plist_

_Dopo aver creato la USB avviaibile, dovresti effettuare qualche tweak sulle porte USB nel caso in cui la tua mobo abbia porte USB 3.0+. Se hai solo porte USB 2.0, allora gli step successivi non sono necessari, ma ti raccomando di seguirli lo stesso_

Aggiungi queste configurazioni nel config.plist tramite Clover Configurator. **_(Patches già applicate nel mio config.plist)_**

**Incrementare il limite delle porte**

Kernel and Kext Patches –> KextToPatch –> +

```html
Name: AppleUSBXHCIPCI
Find: 83bd74ff ffff10
Replace: 83bd74ff ffff1b
Comment: Increase port limit
```

![java-javascript](/img/Hackintosh/PortLimit.png)

**Rinominare EHC a EH0**

ACPI –> DSDT –> Patches –> +

Queste due patches permettono allo **USBInjectAll.kext** di essere caricato:

```html
Comment: change EHC1 to EH01
Find: 45484331
Replace: 45483031
```

```html
Comment: change EHC2 to EH02
Find: 45484332
Replace: 45483032
```

![java-javascript](/img/Hackintosh/EHx1.png)
![java-javascript](/img/Hackintosh/EHx2.png)

Sposta **USBInjectAll.kext** e **XHCI-200-series-injector.kext** nella partizione EFI della USB, in **/EFI/Clover/kexts/Other**.

##### 4.5. Installazione MacOS Sierra

1.  Spegni il computer
2.  Premi l'hotkey **Canc** per scegliere il disco di avvio _(potrebbe differire in base alla scheda madre)_
3.  Seleziona la USB
4.  Alla schermata di Clover, seleziona **Boot Mac OS X from USB**
5.  Arrivato all'Installer, scegli la lingua.
6.  Nella barra in alto seleziona Utilità e quindi **Utility Disco**
7.  Evidenzia il tuo disco scelto per l'installazione di Sierra tramite la colonna a sinistra.
8.  Premi il tasto _Inizializza_
9.  **Nome:** scrivi _Sierra_ (puoi rinominarlo in seguito)
10. **Formato:** segli _Mac OS esteso (journaled)_
11. **Schema:** Scegli _Mappa partizione GUID_
12. Seleziona **Inizializza**
13. Chiudi _Utility Disco_
14. Evidenzia la tua partizione di installazione per Sierra e clicca _Continua_.
15. Dopo il primo riavvio premi nuovamente l'hotkey _Canc_ per scegliere il disco di avvio
16. Seleziona la USB
17. Alla schermata di Clover, scegli **Boot MacOS from the HDD** dove lo hai installato.

**_Se non sai come installare MacOS segui la [Installation Guide](https://www.tonymacx86.com/threads/unibeast-install-macos-sierra-on-any-supported-intel-based-pc.200564/)_**

## 5. Post-Installazione

Dopo un'installazione riuscita, hai bisogno di installare i kexts e le patches necessarie per far funzionare il tutto. In poche parole è la stessa cosa che avviene subito dopo l'installazione di Windows, ma leggermente diversa. Su Windows, i drivers sono contenuti in pacchetti installabili tramite pochi click, mentre in macOS dovremmo installarli **manualmente** passo passo. Come ho detto prima, a seguito del rilascio di macOS 10.12.6 tutto è diventato più semplice a seguito del supporto nativo dei processori Kabylake. Inoltre, tonymacx86 ha rilasciato una nuova versione di MultiBeast, con il supporto alla Serie 200 con processori Kabylake di 7<sup>a</sup> generazione. _Immagina questi steps avresti dovuto seguire prima..._

#### 5.1. Post Installazione con MultiBeast

-   **1° Step** = Copia tutti i file scaricati sulla Scrivania.
-   **2° Step** = Apri Multibeast –> Quick Start –> **UEFI Boot Mode**
    ![java-javascript](/img/Hackintosh/UEFI.png)

-   **3° Step** = Drivers –> Audio –> Seleziona sia **ALC1220** che **100/200 Series Audio**. _(Io ho abilitato anche l'Output a 5.1 canali, dato che lo ho integrato)_
    ![java-javascript](/img/Hackintosh/Audio.png)

_Se hai un codec audio diverso seleziona quello che ti interessa. La versione del codec è specificata tra le componenti della scheda madre_

_Ci sono due modi per far funzionare l'audio. Questo è il primo. Se nel tuo caso non funziona prova il secondo nella sezione “Post Installazione con Clover Configurator/Audio”._

-   **4° Step** = Drivers –> Network –> Seleziona **IntelMausiEthernet v2.3** _(Io ho installato anche il RealtekRTL8111 v2.2.1)_
    ![java-javascript](/img/Hackintosh/Network.png)

-   **5° Step** = Drivers –> USB –> Seleziona **Increase Max Port Limit 200 Series**
    ![java-javascript](/img/Hackintosh/PortLimit.png)

-   **6° Step** = Bootloader –> Seleziona **Clover + Emulated NVRAM**
    ![java-javascript](/img/Hackintosh/CloverBootloader.png)

**_Nota: Dopo aver terminato con Multibeast non dimenticare di aggiornare Clover Bootloader all'ultima versione. Puoi farlo tramite l'app Clover Configurator o tramite il link sopra._**

-   **7° Step** = Customize –> Graphics Configuration –> Seleziona **Intel HD 6xx**
    ![java-javascript](/img/Hackintosh/Graphics.png)

-   **8° Step** = Final Build Configuration Build –> **_Install_**
    ![java-javascript](/img/Hackintosh/MultiBeast.png)

#### 5.2. Post Installazione con Clover Configurator

> _Non necessario se usi il mio config.plist_

##### 5.2.1. Configurazione Base

-   Apri Clover Configurator, quindi monta la Partizione EFI se non lo è già (Multibeast dovrebbe montarla automaticamente)
-   Risolvi il bug del riavvio casuale in fase di spegnimento tramite la spunta **FixShutdown_0004** sotto ACPI –> Fixes
    ![java-javascript](/img/Hackintosh/Shutdown.png)

-   **XMPDetection=Yes** (Se la tua RAM ha un clock maggiore di 2133MHz, come nel mio caso)
    ![java-javascript](/img/Hackintosh/XMP.png)

**_Non chiudere Clover Configurator. Aggiungi tutte le entries dai passi sotto prima o dovrai riaprire Clover Configurator ad ogni step._**

#### 5.2.2. HD Graphics 630 con QuickSync & Contentuti iTunes DRM

Apri Clover Configurator se non aperto.

**Aggiungi patches in DSDT**

ACPI –> DSDT –> Patches –> +

```html
Comment: change GFX0 to IGPU
Find: 47465830
Replace: 49475055
```

![java-javascript](/img/Hackintosh/IGPU.png)

-   Aggiungi la bootflag **shikigva=1** in Boot –> Custom Flags
    ![java-javascript](/img/Hackintosh/shikigva.png)

-   Copia **Shiki.kext** e **AppleALC.kext** ed incollali in **EFI drive/EFI/Clover/kexts/Other**.
    ![java-javascript](/img/Hackintosh/kextsOther.png)

##### 5.2.3. Secondo Metodo Audio

Apri Clover Configurator se non aperto.

-   Assicurati che **Lilu.kext** e **AppleALC.kext** (se hai appena seguito gli step precedenti AppleALC dovrebbe già trovarsi in **kexts/Other**) siano installati. In caso contrario installali.
-   Aggiungi patches in Clover Configurator

**Aggiungi patches in DSDT se non presente.**

ACPI –> DSDT –> Patches –> +

```html
Comment: change HDAS to HDEF
Find: 48444153
Replace: 48444546
```

![java-javascript](/img/Hackintosh/HDxx.png)

**Cambia l'Audio ID a 1 o 2 se non diverso.**

Nell'ultima versione di **AppleALC.kext**, gli audio ID 1, 2 o 11 sono pienamente supportati dai codecs ALC1220 e ALC1220A.

Devices –> Audio –> Cambialo in **1** o **2** o **11**
![java-javascript](/img/Hackintosh/AudioInjection.png)

Esegui **audio_cloverHDMI-130.command** in modo da far funzionare l'HDMI Audio se lo necessiti. Se questo metodo non funziona segui la [guida di Toleda sull'HDMI Audio]\(<https://www.tonymacx86.com/threads/quick-fix-200-series-kaby-lake-audio-onboard-and-or-hd-6x0-hdmi.221618/>.
![java-javascript](/img/Hackintosh/toledaHDMI.png)

#### 5.3. SMBIOS

Abbiamo bisogno di cambiare il nostro SMBIOS ad iMac 18.1 o 18.2 o 18.3 poiché questi sono gli SMBIOS dei nuovi Mac Kabylake. Questo step è necessario perché senza il giusto SMBIOS il sistema non si avvierà e peccherà di alcune funzioni come la gestione energetica, iMessage, l'accelerazione grafica ecc.

Per la perfetta configurazione SMBIOS dai un'occhiata a [questo link](http://www.everymac.com/systems/by_year/macs-released-in-2017.html) e segli l'SMBIOS che più si addice al tuo processore.

Nel mio caso, ho cambiato il mio SMBIOS a 18.2 (perché è l'SMBIOS del Mac con i5-7500).
![java-javascript](/img/Hackintosh/SMBIOS.png)

##### 5.4. Gestione Energetica USB

Per chi voglia implementare correttamente la gestione energetica segua la [guida alla corretta injection per la USB Power Management su Sierra (o successivo)](https://www.tonymacx86.com/threads/guide-usb-power-property-injection-for-sierra-and-later.222266/).

Inoltre, non dimenticare l'aggiunta delle seguentu patches in Kernel and Kext Patches –> Kext To Patch

```html
Name: com.apple.driver.usb.AppleUSBXHCIPCI
Find: 83bd74ff ffff10
Replace: 83bd74ff ffff1b
Comment: change 15 port limit to 26 in XHCI kext (100-series)
```

```html
Name: AppleUSBXHCIPCI
Find: 837d8c10
Replace: 837d8c1b
Comment: Change 15 port limit to 24 in XHCI kext
```

![java-javascript](/img/Hackintosh/AppleUSBXHCIPCI.png)

Come potresti aver notato non ho applicato la prima patch, perché non ne avevo bisogno.

#### 5.5. iMessage

[An iDiot's Guide To iMessage](https://www.tonymacx86.com/threads/an-idiots-guide-to-imessage.196827/) è la migliore guida al corretto funzionamento di iMessage che possiamo trovare su internet, segui solo ogni indicazione passo passo.

## 6. Punteggi Geekbench

I risultati sono davvero buoni, considerato il fatto che stiamo parlando di un un OS in esecuzione su hardware non nativamente supportato.
![java-javascript](/img/Hackintosh/Device.png)
![java-javascript](/img/Hackintosh/Score.png)
![java-javascript](/img/Hackintosh/SCComparison.png)
![java-javascript](/img/Hackintosh/MCComparison.png)
![java-javascript](/img/Hackintosh/OpenCL.png)
![java-javascript](/img/Hackintosh/OpenCLComparison.png)

### 7. Domande Frequenti

-   **Domanda:** Dopo l'installazione di macOS questo non si avvia dall'HHD, ma solo dalla USB!
    		**Risposta:** In questo caso devi prima di tutto avviare appunto da USB. Una volta arrivato alla Scrivania copia l'intera cartella EFI dalla USB sul tuo Hackintosh. Quindi rimpiazza quella già presente nella partizione EFI dell'HHD con quella appena copiata.
-   **Domanda:** Come abilitare le schede video NVIDIA?
    		**Risposta:** Adesso NVIDIA rilascia anche i nuovi Web Driver per GPU con architettura Pascal. Per farle funzionare scarica lo NVIDIA FixUP o semplicemente seleziona l'opzione NVIDIA Web dal nuovo Multibeast.
-   **Domanda:** Questa guida può essere applicata anche ad altre schede madre?
    		**Risposta:** Sì, potrebbe, ma devi adottare i necessari cambiamenti (kexts, config.plist, bootflags...) in post-installazione ed essere sicuro che le opzioni BIOS siano compatibili con l'avvio di Hackintosh.

### 8. Aggiornamenti?

Apple rilascia in media un aggiornamento ogni uno o due mesi. Dopo aver seguito tutti gli step precedenti, potresti aggiornare facilmente tramite il Mac App Store. Ma a volte qualcosa può andare storto. Per questo ti raccomando di mantenere sempre una copia della tua cartella EFI e dei tuoi file più importanti in una partizione/disco a parte. Comunque se qualcosa del genere dovesse succedere scrivimi nei commenti sotto o alla mia mail, nella sezione About.

Problemi Grafici? Dopo l'aggiornamento se non riesci più ad avviare prova disabilitando **Inject Intel** da **Boot/Options/Graphics Injector/Untick inject-intel**. Una volta raggiunta la Scrivania, installa **Lilu.kext** e **IntelGraphicsFixup.kext** in **Library/Extension**. Se questo non ti aiuta ancora segui la relativa sezione nella guida sovrastante. Se tutti i kexts necessari sono già installati, però, non dovresti avre alcun problema ad aggiornare.

Assicurati che l'audio funzioni perché il secondo metodo potrebbe essere affetto da eventuali aggiornamenti. Se hai problemi audio, segui nuovamente i relativi step nella guida sopra.

![java-javascript](/img/Hackintosh/HighSierra.png)

### 9. Ringraziamenti

-   [jktaurus8](https://www.tonymacx86.com/members/jktaurus8.1548388/) per la sua [fantastica guida](https://www.tonymacx86.com/threads/updated-for-multibeast-9-2-1-and-sierra-10-12-6-sierra-on-200-series-with-kabylake-processor.218494/).
-   [RehabMan](https://www.tonymacx86.com/members/rehabman.429483/)
-   [GhostHitWall](https://www.tonymacx86.com/members/ghosthitwall.1415514/)
-   [tonymacx86](https://www.tonymacx86.com/members/tonymacx86.3/)
-   [onmybikedrunk](https://www.tonymacx86.com/members/onmybikedrunk.1085297/)
-   [toleda](https://www.tonymacx86.com/members/toleda.2393/)
-   [P1LGRIM](https://www.tonymacx86.com/members/p1lgrim.374452/)
-   Te, se hai letto l'intera guida. In caso contrario... beh... fanghule.
