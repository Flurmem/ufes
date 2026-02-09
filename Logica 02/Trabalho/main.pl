% Molécula: Ácido Glioxílico (s3)
atomo(s3, c1, carbono).
atomo(s3, c2, carbono).
atomo(s3, o1, oxigenio). % da carbonila do ácido
atomo(s3, o2, oxigenio). % da hidroxila do ácido
atomo(s3, o3, oxigenio). % do aldeído
atomo(s3, h1, hidrogenio). % da hidroxila
atomo(s3, h2, hidrogenio). % do aldeído

% Ligações do Grupo Ácido (C1)
ligacaodupla(s3, c1, o1).
ligacaosimples(s3, c1, o2).
ligacaosimples(s3, o2, h1).

% Ligação entre carbonos
ligacaosimples(s3, c1, c2).

% Ligações do Grupo Aldeído (C2)
ligacaodupla(s3, c2, o3).
ligacaosimples(s3, c2, h2).

%Molecula Simples 11 (Haleto Iodo)

atomo(s11,h1,hidrogenio).
atomo(s11,h2,hidrogenio).
atomo(s11,h3,hidrogenio).
atomo(s11,c,carbono).
atomo(s11,i,iodo).

ligacaosimples(s11,h1,c).
ligacaosimples(s11,h2,c).
ligacaosimples(s11,h3,c).
ligacaosimples(s11,c,i).

ligacaodupla(xx,a,b).
ligacaotripla(xx,a,b).

%Molecula Simples 12 (Nada)

atomo(s12,h1,hidrogenio).
atomo(s12,h2,hidrogenio).
atomo(s12,h3,hidrogenio).
atomo(s12,h4,hidrogenio).
atomo(s12,h5,hidrogenio).
atomo(s12,h6,hidrogenio).
atomo(s12,c1,carbono).
atomo(s12,c2,carbono).

ligacaosimples(s12,h1,c1).
ligacaosimples(s12,h2,c1).
ligacaosimples(s12,h3,c1).
ligacaosimples(s12,c1,c2).
ligacaosimples(s12,c2,h4).
ligacaosimples(s12,c2,h5).
ligacaosimples(s12,c2,h6).

ligacaodupla(xx,a,b).
ligacaotripla(xx,a,b).

acido_carboxilico(X) :-
    atomo(X, C, carbono),
    atomo(X, O1, oxigenio),
    atomo(X, O2, oxigenio),
    atomo(X, H, hidrogenio),
    ligacaodupla(X, C, O1),
    ligacaosimples(X, C, O2),
    ligacaosimples(X, O2, H).


aldeido(X) :-
    atomo(X, C1, carbono),
    atomo(X, C2, carbono),
    atomo(X, O, oxigenio),
    atomo(X, H, hidrogenio),
    ligacaodupla(X, C2, O),
    ligacaosimples(X, C1, C2),
    ligacaosimples(X, C2, H).

cetona(X) :-
    atomo(X, C1, carbono),
    atomo(X, C2, carbono),
    atomo(X, C3, carbono),
    atomo(X, O, oxigenio),
    ligacaodupla(X, C2, O),
    ligacaosimples(X, C1, C2),
    ligacaosimples(X, C2, C3).

amina(X) :-
    atomo(X, N, nitrogenio),
    (
    amina_primaria(X, N);
    amina_secundaria(X, N);
    amina_terciaria(X, N)
    )
    .

amina_primaria(X, N) :-
    atomo(X, N, nitrogenio),
    atomo(X, C1, carbono),
    atomo(X, H1, hidrogenio),
    atomo(X, H2, hidrogenio),
    ligacaosimples(X, N, C1),
    ligacaosimples(X, N, H1),
    ligacaosimples(X, N, H2),
    H1 \= H2.

amina_secundaria(X, N) :-
    atomo(X, N, nitrogenio),
    atomo(X, C1, carbono),
    atomo(X, C2, carbono),
    atomo(X, H1, hidrogenio),
    ligacaosimples(X, N, C1),
    ligacaosimples(X, N, C2),
    ligacaosimples(X, N, H1),
    C1 \= C2.

amina_terciaria(X, N) :-
    atomo(X, N, nitrogenio),
    atomo(X, C1, carbono),
    atomo(X, C2, carbono),
    atomo(X, C3, carbono),
    ligacaosimples(X, N, C1),
    ligacaosimples(X, N, C2),
    ligacaosimples(X, N, C3),
    C1 \= C2, C1 \= C3, C2 \= C3.

alcool(X) :-
    atomo(X, C, carbono),
    atomo(X, H, hidrogenio),
    atomo(X, O, oxigenio),
    ligacaosimples(X, C, H),
    ligacaosimples(X, O, H).

haleto(X) :-
    atomo(X, f, fluor); 
    atomo(X, cl, cloro);
    atomo(X, b, bromo);
    atomo(X, i, iodo).


testa_todos(X) :-
    % 1. ÁCIDO CARBOXÍLICO
    (   acido_carboxilico(X) 
    ->  write('Grupo Principal: Acido Carboxilico, Sufixo: oico'), nl, 
        S1 = secundario
    ;   S1 = principal 
    ),

    % 2. ALDEÍDO
    (   aldeido(X) 
    ->  (   S1 == principal
        ->  write('Grupo Principal: Aldeido'), nl, write(' Sufixo: al'), nl, 
            S2 = secundario
        ;   write('Grupo Secundario: Aldeido, Sufixo: oxo'), nl, 
            S2 = secundario
        )
    ;   S2 = S1 
    ),

    % 3. CETONA
    (   cetona(X) 
    ->  (   S2 == principal 
        ->  write('Grupo Principal: Cetona'), nl, write(' Sufixo: ona'), nl, 
            S3 = secundario
        ;   write('Grupo Secundario: Cetona, Sufixo: oxo'), nl, 
            S3 = secundario
        )
    ;   S3 = S2  
    ),

    % 4. AMINA
    (   amina(X) 
    ->  (   S3 == principal
        ->  write('Grupo Principal: Amina'), nl, write(' Sufixo: amina'), nl, 
            S4 = secundario
        ;   write('Grupo Secundario: Amina, Sufixo: amino'), nl, 
            S4 = secundario
        )
    ;   S4 = S3  
    ),

    % 5. ÁLCOOL
    (   alcool(X) 
    ->  (   S4 == principal
        ->  write('Grupo Principal: Alcool'), nl, write(' Sufixo: ol'), nl, 
            S5 = secundario
        ;   write('Grupo Secundario: Alcool, Sufixo: hidroxi'), nl, 
            S5 = secundario
        )
    ;   S5 = S4  
    ),

    % 6. HALETO
    (   haleto(X) 
    ->  (   S5 == principal
        ->  write('Grupo Principal: Haleto'), nl, write(' Sufixo: o'), nl,
            S6 = secundario
        ;   write('Grupo Secundario: Haleto, Sufixo: fluor/cloro...'), nl, 
            S6 = secundario
        )
    ;   S6 = S5
    ),

    % Nenhum grupo funcional encontrado
    (  S6 == principal
    -> write('Nenhum grupo funcional encontrado.'), nl
    ;  true
    ).