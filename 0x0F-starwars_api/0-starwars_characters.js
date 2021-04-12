#!/usr/bin/node

const request = require('request');
const SWepisode = process.argv;
// EPISODE TWO CHARACTERISTICS
const SWAPI = 'https://swapi-api.hbtn.io/api/films/' + SWepisode[2];

// REQUESTING STAR WARS API
request(SWepisode + SWAPI, async function (err, res, body) {
  if (err) {
    return(console.log(err));
  }
  else {
    const SWAPIcharacters = JSON.parse(body).characters;
    let characters;
    for (characters of SWAPIcharacters) {
      await new Promise(function (resolve, reject) {
        request(characters, function (err, res, body) {
          if (err) {
            return(console.log(err));
          }
          console.log(JSON.parse(body).name);
          resolve();
        });
      });
    }
  }
});
