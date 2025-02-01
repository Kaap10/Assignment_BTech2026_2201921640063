-- Approach-1
SELECT
    name, population, area
FROM
    World
WHERE 
    area >= 3000000 || population >= 25000000;

-- Using UNION
SELECT
    name, population, area
FROM
    World
WHERE 
    area >= 3000000
UNION
SELECT
    name, population, area
FROM
    World
WHERE 
    population >= 25000000;