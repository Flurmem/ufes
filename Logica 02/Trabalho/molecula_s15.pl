% Molécula: Ácido 3-bromobutanoico (s15)
atomo(s15, c1, carbono).   % Carbono do ácido
atomo(s15, c2, carbono).   % Carbono vizinho
atomo(s15, c3, carbono).   % Carbono secundário onde estará o Bromo
atomo(s15, c4, carbono).   % Carbono terminal
atomo(s15, o1, oxigenio).  % Oxigênio da carbonila (=O)
atomo(s15, o2, oxigenio).  % Oxigênio da hidroxila (-OH)
atomo(s15, h1, hidrogenio).% Hidrogênio do ácido
atomo(s15, br, bromo).     % O Haleto

% Ligações do Grupo Ácido (C1)
ligacaodupla(s15, c1, o1).
ligacaosimples(s15, c1, o2).
ligacaosimples(s15, o2, h1).

% Cadeia Carbônica
ligacaosimples(s15, c1, c2).
ligacaosimples(s15, c2, c3).
ligacaosimples(s15, c3, c4).

% Ligação do Haleto (No carbono secundário C3)
ligacaosimples(s15, c3, br).

