SELECT avg(rating) AS avarete_rating FROM ratings WHERE movie_id IN (SELECT ID FROM movies WHERE year == 2012);
