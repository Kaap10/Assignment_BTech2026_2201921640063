# Write your MySQL query statement below
SELECT
    name
FROM
    Customer
WHERE
    referee_id is NULL || referee_id != '2';
    -- IFNULL(referee_id , 0) <> 2;