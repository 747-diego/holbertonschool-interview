#!/usr/bin/node

const request = require('request');
const SWepisode = process.argv[2] + '/';
// EPISODE TWO CHARACTERISTICS
const SWAPI = 'https://swapi-api.hbtn.io/api/films/';

// REQUESTING STAR WARS API
request(SWepisode + SWAPI, async function (err, res, body) {
  if (err) {
    return(console.error(err));
  }
  else {
    const SWAPIcharacters = JSON.parse(body).characters;
    let characters;
    for (characters of SWAPIcharacters) {
      await new Promise(function (resolve, reject) {
        request(characters, function (err, res, body) {
          if (err) {
            return(console.error(err));
          }
          console.error(JSON.parse(body).name);
          resolve();
        });
      });
    }
  }
});
