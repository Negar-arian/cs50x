
--find crime scene description
SELECT description
  FROM crime_scene_reports
 WHERE month = 7
   AND day = 28
   AND year = 2021
   AND street = 'Humphrey Street';

--find interviews transcripts about the thief in bakery
SELECT transcript
  FROM interviews
 WHERE day = "28"
   AND month = "7"
   AND year = "2021"
   AND transcript like "%bakery%";

--find list of people who leaved the bakery after 10:15
SELECT name
  FROM people
  JOIN bakery_security_logs
    ON people.license_plate = bakery_security_logs.license_plate
 WHERE day = "28"
   AND month = "7"
   AND year = "2021" AND hour = "10"
   AND minute >= "15"
   AND minute < "25"
   AND activity = "exit";

--find list of people who withdraw money in Leggett Street on July 28, 2021
SELECT DISTINCT name
           FROM people
           JOIN bank_accounts
             ON people.id = bank_accounts.person_id
           JOIN atm_transactions
             ON bank_accounts.account_number = atm_transactions.account_number
          WHERE day = "28"
            AND month = "7"
            AND year = "2021"
            AND transaction_type = "withdraw"
            AND atm_location = "Leggett Street";

--find people who called someone for less that a minute
SELECT name
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.caller
 WHERE day = "28"
   AND month = "7"
   AND year = "2021"
   AND duration < "60";

--find people who has earlier tiket for July 29, 2021 and origin_airport is in Fiftyville
SELECT name
  FROM people
  JOIN passengers
    ON people.passport_number = passengers.passport_number
  JOIN flights
    ON flights.id = passengers.flight_id
  JOIN airports
    ON airports.id = flights.origin_airport_id
 WHERE day = "29"
   AND month = "7"
   AND year = "2021"
   AND city = "Fiftyville"
   AND flight_id =
      (SELECT flights.id
         FROM people
         JOIN passengers
           ON people.passport_number = passengers.passport_number
         JOIN flights
           ON flights.id = passengers.flight_id
         JOIN airports
           ON airports.id = flights.origin_airport_id
        WHERE day = "29"
          AND month = "7"
          AND year = "2021"
          AND city = "Fiftyville"
     ORDER BY hour , minute
        LIMIT 1)

--finding the intersect between those four group of people
SELECT name
  FROM people
  JOIN passengers
    ON people.passport_number = passengers.passport_number
  JOIN flights
    ON flights.id = passengers.flight_id
  JOIN airports
    ON airports.id = flights.origin_airport_id
 WHERE day = "29"
   AND month = "7"
   AND year = "2021"
   AND city = "Fiftyville"
   AND flight_id =
       (SELECT flights.id
          FROM people
          JOIN passengers
            ON people.passport_number = passengers.passport_number
          JOIN flights
            ON flights.id = passengers.flight_id
          JOIN airports
            ON airports.id = flights.origin_airport_id
         where day = "29"
           AND month = "7"
           AND year = "2021"
           AND city = "Fiftyville"
      ORDER BY hour , minute
         limit 1)
     INTERSECT
        SELECT DISTINCT name
          FROM people
          JOIN bank_accounts
            ON people.id = bank_accounts.person_id
          JOIN atm_transactions
            ON bank_accounts.account_number = atm_transactions.account_number
         WHERE day = "28"
           AND month = "7"
           AND year = "2021"
           AND transaction_type = "withdraw"
           AND atm_location = "Leggett Street"
     INTERSECT
        SELECT name
          FROM people
          JOIN phone_calls
            ON people.phone_number = phone_calls.caller
         WHERE day = "28"
           AND month = "7"
           AND year = "2021"
           AND duration < "60"
     INTERSECT
        SELECT name
          FROM people
          JOIN bakery_security_logs
            ON people.license_plate = bakery_security_logs.license_plate
         WHERE day = "28"
           AND month = "7"
           AND year = "2021"
           AND hour = "10"
           AND minute >= "15"
           AND minute < "25"
           AND activity = "exit";

--find Bruce's accomplice (Robin)
SELECT name
  FROM people
 WHERE phone_number IN
       (SELECT receiver
          FROM phone_calls
         where caller =
               (SELECT caller
                  FROM people
                  JOIN phone_calls
                    ON people.phone_number = phone_calls.caller
                 Where name = "Bruce"
                 limit 1)
          AND month = 7
          AND day = 28
          AND duration < 60)

--find where the thief escaped to
SELECT city
  FROM people
  JOIN passengers
    ON people.passport_number = passengers.passport_number
  JOIN flights
    ON flights.id = passengers.flight_id
  JOIN airports
    ON airports.id = flights.destination_airport_id
 WHERE year = 2021
   AND month = 7
   AND day = 29
   AND name = "Bruce"

