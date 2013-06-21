==================
Web Frontend Notes
==================

CSS override priority
=====================

From `this page`__:

    Overriding-wise, the sheet imported last will override the imported ones that come before -- i.e. in the example above, 'advanced.css' has more weight than 'style.css' because it is imported below it. Imported stylesheets have the least influence over the final presentation of a page overall, as linked sheets will override them. So we finally have a full cascade order:

    *   the style attribute overrides
    *   a style block, which overrides
    *   a linked stylesheet, which overrides
    *   an imported sheet.

__ http://www.yourhtmlsource.com/stylesheets/advancedcss.html

CSS inheritance
===============

From `this page`__:

    CSS inheritance works on a property by property basis. When applied to an element in a document, a property with the value 'inherit' will use the same value as the parent element has for that property.

__ http://www.yourhtmlsource.com/stylesheets/advancedcss.html

Negtive margins
===============

From `this page`__:

    CSS widths in general can be a little confusing. Absolute widths are easy. Relative widths can lead to some interesting behaviour. Basically, percentage widths are relative to the containing element. If the parent element has an absolute width then it's easy to work out. Often it doesn't though so you can get into complicated calculations of how a browser calculates how much space it needs. If all its children are percentage width then it'll often end up having less width than the designer usually intends.

    So when you see ``margin-left: -100%``, that basically means move this element outside its parent to the left the complete width of the parent. One consequence of negative margins (in particular) is that the space they move into often won't cater for them being there and you have to take this into account when planning layout.

    Another good tip is that if you have this situation:

    .. code:: html

        <div id="outer">
          Outer
          <div id="inner">Inner</div>
        </div>
        <style type="text/css">
        #outer { width: 100px; }
        #inner { width: 50px; margin-left: -100px; }
        <style>

    it won't really work. Or rather it'll work on (iirc) Firefox but not on IE (any version). So if you want to do something like this, you need to use a containing element.

    .. code:: css

        <div id="outer">
          Outer
          <div id="wrap">
            <div id="inner">Inner</div>
          </div>
        </div>
        <style type="text/css">
        #outer { width: 100px; }
        #wrap { width: 100px; margin-left: -100px; }
        #inner { width: 50px; }
        <style>

__ http://stackoverflow.com/questions/1051844/negative-margins-in-css-good-tutorial-and-tricks-site
