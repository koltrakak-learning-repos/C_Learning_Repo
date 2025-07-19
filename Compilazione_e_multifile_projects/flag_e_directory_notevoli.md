### gcc flags
- \-c option
    - says not to run the linker.
    -  Then the output consists of object files (.o) output by the assembler.

- \-l (library)
    - Search the library named library when linking. 
    - The -l option is passed directly to the linker by GCC.  Refer to your linker documentation for exact details.  The general description below applies to the GNU linker.
    - The linker searches a **standard list of directories for the library** (ad esempio /usr/lib/x86_64-linux-gnu/).  The directories searched include several standard system directories plus **any that you specify with -L**.
    - It makes a difference where in the command you write this option; the linker searches and processes libraries and object files in the order they are specified.  Thus, foo.o -lz bar.o searches library z after file foo.o but before bar.o.  If bar.o refers to functions in z, those functions may not be loaded.
    - nota: non c'è bisogno di specificare l'estensione e di inserire il prefisso 'lib' quando aggiungi una libreria 

- \-L 
    - specifica una directory (oltre a quelle standard del sistema) in cui cercare le librerie da includere

- \-I (include path)
    - specifica dove trovare gli header file per le librerie utilizzate nel progetto
    - simile a meno -L ma per header file piuttosto che per le implementazioni
    - il linker cerca le librerie mentre il compilatore cerca gli header file
    - anche qui ci sono delle directory di default in cui il compilatore va a cercare quando si specifica un include path con le parentesi angolari (es. /usr/include/)


**NB**: le directory standard in cui il linker va a cercare le librerie possono essere specificate in vari modi:
- variabili di ambiente
- oppure dentro a ```/etc/ld.so.conf.d``` 
- a quanto pare **sia il compilatore che il linker NON cerca ricorsivamente** nelle sottodirectory specificate

