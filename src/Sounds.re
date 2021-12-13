type audio;
[@bs.new] external createAudio: string => audio = "Audio";
[@bs.send] external playInternal_: audio => unit = "play";
[@bs.send] external pause: audio => unit = "pause";
[@bs.set] external setCurrentTime: (audio, int) => unit = "currentTime";
[@bs.set] external setVolume: (audio, float) => unit = "volume";
[@bs.set] external onEnded: (audio, unit => unit) => unit = "onended";

let play = (audio: audio) => {
  playInternal_(audio);
  setCurrentTime(audio, 0);
};

let yksiNoise1 = {
  let audio = createAudio("assets/sfx/kolme_noise_1.mp3");
  setVolume(audio, 0.2);
  audio;
};
let kaxigNoise1 = {
  let audio = createAudio("assets/sfx/kolme_noise_1.mp3");
  setVolume(audio, 0.2);
  audio;
};
let kolmeNoise1 = {
  let audio = createAudio("assets/sfx/kolme_noise_1.mp3");
  setVolume(audio, 0.2);
  audio;
};

let museumMusicVolume = 0.5;

let museumMusic = {
  let audio = createAudio("assets/sfx/Vivarium_Brimming.mp3");
  setVolume(audio, museumMusicVolume);
  audio;
};
