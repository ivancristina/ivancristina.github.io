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

## Preparations

* Prima di tutto ricorda che (nonostante sia davvero stabile) questa è una **versione beta**, usala con cautela o aspetta per la versione finale se sei troppo inesperto
* Assicurati che su Impostazioni → Generali → Spazio Libero non ci sia alcun **aggionrnamento OTA** (apparirà come *iOS 12.x*): in caso ce ne sia uno, eliminalo prima di inizia il processo di jailbreaking
![alt text](/img/in-post/JB/iStorage.png "Check for the OTA in here")
* In modo da bloccare definitivamente gli aggionrnamenti OTA installa il *profilo tvOS* [clicccando](https://raw.githubusercontent.com/Jwhite077/NOOTA/master/tvOS_12_Beta_Profile.mobileconfig). Il tuo dispositivo richiederà il tuo codice di sblocco ed in seguito si riavvierà. Appena hai riavviato, gli aggionrnamenti spariranno fin quando non rimuoverai il profilo. Nella schermata "aggionrnamenti di sistema" otterrai infatti questo errore
![alt text](/img/in-post/JB/tvOS.png "Install the tvOS profile")
* Se hai già usato **rootlessJB** su iOS 12, disinstallalo cliccando sul tasto “Uninstall” all'interno del tool

## Download

Ci sono due modi per installare unc0ver. Puoi installarlo sia da PC tramite un tool chiamato **Cydia Impatactor**, sia tramite store di terze parti. In questa guida però, illustrerò un metodo ancora più semplice per gli utenti italiani.

#### @JailbreakItalia

Il gruppo Telegram di Jailbreak Italia offre (oltre ad un incredibile supporto utenti) un bot che permette tramite pochi semplici passi di installare l'ultima versione di unc0ver in maniera completamente gratuita, rapida ed intuitiva.
Scaricate (se non lo avete già fatto - e sarebbe un errore) [Telegram](https://itunes.apple.com/it/app/telegram-messenger/id686449807?l=en&mt=8). Per i pochi che non dovessero conoscerlo, è l'alternativa *open-source*, sicura, versatile e leggera a WhatsApp. Telegram permette però - oltre a tantissime altre funzioni davvero innovative - di accedere a gruppi, supergruppi e canali. La community italiana ha infatti scelto il supergruppo **Jailbreak Italia** come centro di ritrovo e di supporto per gli appassionati del Jailbreak.
Per entrare nel gruppo, basta [cliccare qui](https://t.me/JailbreakItalia).
Una volta visionate le regole - ed eventualmente salutare *:P* - basta scrivere "**!uncoverdl**" (senza virgolette) ed inviare il messaggio. Un bot vi risponderà automaticamente chiedendo quale versione volete installare. Selezionate **unc0ver Beta**, visionate le avvertenze e all'apparizione di un popup di conferma per l'installazione, date il consenso.
Prima di aprire l'app avrete bisogno di un'ultima cosa: recatevi su Impostazioni → Generali → Profili, aprite il profilo aziendale che apparirà (usato per firmare l'app) e cliccate su *Verifica*.
![alt text](/img/in-post/JB/Profiles.png "Trust the profile")

L'app sarà ormai verificata e potrai aprirla.
![alt text](/img/in-post/JB/unc0ver Icon.png "You can now open unc0ver")

## Jailbreaking

Whenever you open unc0ver go to the *Settings* tab and make sure that you have the default configurations. As for the time I'm writing, these are the default ones.
![alt text](/img/in-post/JB/unc0ver Settings.png "Leave everything as it is")

Ok, now go back to the home screen of unc0ver. You will see a giant button called **Jailbreak**. Once you're ready, click it. Once you click it, you end up restarting or respringing: I'll talk about it later.
![alt text](/img/in-post/JB/unc0ver.png "Press the Jailbreak button")

Click it now. The device will run the exploit and if that's successful it will reach the first stage, the **snapshot renaming"**. Now, press *OK* and the device will restart.
![alt text](/img/in-post/JB/Snapshot Rename.png "First step done")

It could happen that reached the step **2/38** the device could *panic* because the exploit fails and the device will automatically reboot. Don't mind, that's normal, you just have to retry.
![alt text](/img/in-post/JB/unc0ver Exploit.png "The device could panic at step 2/38")

Once again, open unc0ver and click the Jailbreak button once again. If everything goes well, you will reach the **bootstrap extraction** stage. Press OK and reboot again.
![alt text](/img/in-post/JB/Bootstrap Extracted.png "First step done")

That should be the last time: press Jailbreak again. At a certain point the device will **respring**: the screen will go black and will dim, at the center of the screen there should be a rotating circle (as when the device shutdown). Wait for it to finish and you should finally see **Cydia**!
![alt text](/img/in-post/JB/Cydia Icon.png "Cydia appeared")

Now the jailbreak is activated, but remember that this is a ***semi-unthetered*** jailbreak. That means that whenever you turn off your device you will re-enter in jailed mode. But that's not a big deal: open unc0ver, press the *Jailbreak* button and after a respring you will reactivate your jailbreak.

Remember to update even the unc0ver app itself from Ignition or download and resign the new IPA via Impactor in order to always have the most stable experience! Once updated, open the app and press the *Re-Jailbreak* button.
![alt text](/img/in-post/JB/unc0ver ReJailbreak.png "Press the Re-Jailbreak button")

## Setup Cydia

Now it's time to set up Cydia. First of all open it up and you will see this welcome screen.
![alt text](/img/in-post/JB/Cydia.png "Welcome")

Go into the *Sources* tab on the bottom, and you will see this screen.

Those are the **repositories**, where all the **tweaks** are stored and distributed from. Most of the tweaks are free, but some are paid. ***DO NOT PIRATE THEM***, for various reasons. First of all, because developers spend their time offering us these wonderful customizations which we would never have and supporting them paying some of their tweaks is the less we could do. Secondly, because pirated tweaks could lead to **bootloops**, forcing you to restoring your iDevice, losing both the jailbreak and ***all*** **your data**. Always download them from the official repo (usually they are *BigBoss*, *Chariz* or *Dynastic*). If you are not sure about the repo of the tweak you're searching for, Google "`name of your tweak here` repo". You'll surely find it.
![alt text](/img/in-post/JB/Cydia Sources.png "Sources tab")

Whenever you *Refresh* the sources a red banner will appear. By doing that you'll reload the *index* of every repo and if there are updates, they will show up. It's usually better to update your tweaks in order to improve their stability. If any *Essential update* will show up, please do a *Complete update*. Those packages are updated from the maintainer of your jailbreak and makes your jailbreak more stable.
![alt text](/img/in-post/JB/Cydia Necessary Update.png "Perform a complete update")

But how to add a repo? That's super easy. Most of the repos now have specific button, prompting to add the repo, but it could also happen that you should manually add it. In that case press the *Edit* button on top-right, then *Add* and pasting the URL of the repo and finally *Add source*. In this case I'll add the `http://tigisoftware.com/cydia`, the repo of **Filza**. We'll talk about it later.
![alt text](/img/in-post/JB/Cydia Sources Add.png "Add the source")

If you want to delete a repo, simply press *Edit* and then delete it with the red button next to it.
![alt text](/img/in-post/JB/Cydia Sources Remove.png "Remove source in this way")

### Installing tweaks

Here comes the fun part: installing tweaks. Tweaks are packages which customize your system, just by adding customizations or even adding apps. In this example we'll install a famous jailbroken app called **Filza**. It's a package manager with ***root*** priviledges. If you are unexpirienced don't use it, but it's always good having it.

In Cydia, refresh the sources, then go to the *Search* tab and write your package name. There will be more than one result, in this case pick the **64bit** version (since you are running unc0ver, you must be 64bit).
![alt text](/img/in-post/JB/Cydia Search Filza.png "Search for the packages here")

A popup window will show up. If you want to install something else *Continue Queuing*, otherwise just *Confirm*.
![alt text](/img/in-post/JB/Cydia Installation Confirm.png "Press confirm to install")

You'll se a **verbose** output of what's happening.
![alt text](/img/in-post/JB/Cydia Filza Installation.png "Verbose output")

Once you'll read *Restart SpringBoard* just press it. After a respring you'll see your new tweaks or your new apps!
![alt text](/img/in-post/JB/Cydia Restart SpingBoard.png "Press Restart SpringBoard")

And now you should see Filza installed!
![alt text](/img/in-post/JB/Filza Icon.png "Here it is")

If you want to remove a tweak you installed, go to the *Installed* tab, open the tweak you want to remove, click *Edit* and then *Remove*. Even in this case you can queue more actions.
![alt text](/img/in-post/JB/Cydia Installed.png "This is the Installed tab")

As I said tweaks can also customize various aspects of iOS, in this case you can see the settings before and after installing the tweak **System Info**.
![alt text](/img/in-post/JB/iOS Info.png "Before")
![alt text](/img/in-post/JB/iOS Info Tweak.png "After")

As I said, periodically check for updates by refreshing the sources. If there are some updates, they will show up in the *Changes* section.
![alt text](/img/in-post/JB/Cydia Changes.png "Updates will show up here")

### The End

You are now ready to ~~mess~~ play with your device.

You can find my socials in the footer of this web page, in case you want to follow me or need urgent help.

> Happy Jailbreaking!
