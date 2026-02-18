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