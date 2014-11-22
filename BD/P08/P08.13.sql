-- FICHA 8
-- 13
-- Actualize o campo GENERO_PREFERIDO da tabela AUTORES_BACKUP de modo a
-- referir-se ao género de livros que o autor mais escreveu.

UPDATE autores_backup
SET genero_preferido = (
  SELECT favorito.genero
  FROM (
      SELECT A.codigo_autor, A.genero
      FROM (SELECT codigo_autor, genero, count(genero) n FROM livros_backup GROUP BY codigo_autor, genero) A,
          (SELECT codigo_autor, MAX(n) maximo
           FROM (SELECT codigo_autor, genero, count(genero) n FROM livros_backup GROUP BY codigo_autor, genero)
           GROUP BY codigo_autor) B
      WHERE A.codigo_autor = B.codigo_autor
      AND A.n = B.maximo
    ) favorito
  WHERE autores_backup.codigo_autor = favorito.codigo_autor
);

-- Solução provisória...
-- O que á que acontece se existir mais que um género de livros que o autor mais escreveu?
-- Por exemplo: o autor X apenas escreveu 2 livros do género 'POLICIAL' e 2 livros do género 'ROMANCE'.
