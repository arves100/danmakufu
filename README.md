
# Touhou Danmakufu ph3.5 ~ Woo Edition

All hail our lord and savior Mima and our queen, Kogasa's Woo.
This version of Danmakufu is made for the purposes of both optimization and fixing some issues with the original source that mkm dropped.  (See James7132's repo for a link to the original download)
<b>This version of Danmakufu is completely backwards compatible with ph3.  If something doesn't work as expected, please make an issue thread.</b>

## Changes

Here's a list of changes compared to original Danmakufu that may enable your computer to use it better.
</br>✻Changes the way RNG is determined to be much more stable than previously (mt19937 compared to a Mersenne Twister from 1996, lmao)
</br>✻Removes a lot of repeated function calls (in bullet movement only as of 6/24/2019)
</br>✻Removes a LOT of unnecessary vertices calculated (but not used) when drawing curvy lasers (see Special Thanks)
</br>✻Enables a lot of optimization flags that mkm for some reason disabled (basically everything under /O2)
</br>✻Attempts to fix the window resolution issue (not quite 640x480) that occurs with the source when built, but not the original ph3 build.

## Special Thanks

Natashi - for the code that made curvy lasers run a lot better than what I could do</br>
Trickysticks - for the woo art that graced the world

## Contributions
Unlike the original source, this version is *technically* in active development (though my primary focus will be Danmakufu Remastered - check out Ultima's repo for that <a href=https://github.com/ultimaomega/touhoudanmakufuremastered>here</a>) so pull requests are absolutely accepted provided they don't break the game.  Though bear in mind that as this version of DNH still relies on mkm's original source code (most of which is either very unoptimized even with optimization flags or is very outdated in execution), there is only so far we can go in attempting to make it better. </br> In addition, *this build will be focused on optimization and performance improvements only*.  If you want to suggest brand new features, bug fixes, etc. please turn your attention to Danmakufu Remastered instead - this version is made to be completely backwards compatible, and as such new features can't simply be added.

## License

(from James7132's repo of the original source, maintaining the same license.)
This code is licensed under the NYSL (Niru nari Yaku nari Suki ni shiro License'). 
Main translated points:
