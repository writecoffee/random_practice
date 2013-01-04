<TeXmacs|1.0.7.14>

<style|generic>

<\body>
  <doc-data|<doc-title|Detect Loop in a Linked
  List>|<doc-author-data|<author-name|Silao Xu>>>

  Suppose the entire length of the graph is <math|L>, the length of the loop
  is <math|r>. Given two nodes, <math|p<rsub|f>> and <math|p<rsub|s>>, depart
  at the same time with speed <math|v<rsub|f>> and <math|v<rsub|s>>, where
  <math|v<rsub|f> = 2v<rsub|s>>.

  Also we should notice that assuming both nodes start in the beginning of
  the loop, when they meet, <math|p<rsub|f>> would be <math|r >-distance
  <math|>faster than <math|p<rsub|s>>. Because we have:

  <\eqnarray*>
    <tformat|<table|<row|<cell|r>|<cell|=>|v<rsub|s>t<eq-number><label|lab1>>|<row|<cell|v<rsub|f>>|<cell|=>|<cell|2v<rsub|s>,<eq-number><label|lab2>>>>>
  </eqnarray*>

  where <math|t> is the time they spend on the loop. We substitute
  <math|v<rsub|s>> in (<reference|lab1>) with
  <specific|latex|<frac{v_2}{2}>><em|<math|<frac|v<rsub|f>|2>>>
  (<reference|lab2>), we can get <math|v<rsub|f<rsub|>>t = 2r>, which means
  <math|p<rsub|f>> has passed 2 laps and <math|v<rsub|f>t - v<rsub|s<rsub|>>t
  = r>. So we can conclude that when they meet in the loop,
  <math|p<rsub|f<rsub|>> >has to run one lap faster than <math|p<rsub|s>>.

  Now when <math|p<rsub|s>> enters the loop, it would pass distance <math|d>
  with <math|p<rsub|f>>'s passing the loop with distance <math|d>. It would
  be:

  <\eqnarray*>
    <tformat|<table|<row|<cell|v<rsub|f>t
    \<noplus\>\<noplus\>+d-v<rsub|s>t>|<cell|=>|<cell|r>>|<row|<cell|v<rsub|s>t>|<cell|=>|<cell|r
    - d.<eq-number><label|lab3>>>>>
  </eqnarray*>

  From (<reference|lab3>) we know that <math|s<rsub|s>> is smaller than one
  loop (<math|s> denotes the distance that pointer passes on the loop).\ 
</body>

<\initial>
  <\collection>
    <associate|language|american>
    <associate|page-type|letter>
  </collection>
</initial>

<\references>
  <\collection>
    <associate|lab1|<tuple|1|?>>
    <associate|lab2|<tuple|2|?>>
    <associate|lab3|<tuple|3|?>>
  </collection>
</references>