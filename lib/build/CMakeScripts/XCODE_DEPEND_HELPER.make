# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.prpg.Debug:
/Users/adodman/mcdreamer/SFMLrpg/lib/build/Debug/libprpg.a:
	/bin/rm -f /Users/adodman/mcdreamer/SFMLrpg/lib/build/Debug/libprpg.a


PostBuild.prpg.Release:
/Users/adodman/mcdreamer/SFMLrpg/lib/build/Release/libprpg.a:
	/bin/rm -f /Users/adodman/mcdreamer/SFMLrpg/lib/build/Release/libprpg.a


PostBuild.prpg.MinSizeRel:
/Users/adodman/mcdreamer/SFMLrpg/lib/build/MinSizeRel/libprpg.a:
	/bin/rm -f /Users/adodman/mcdreamer/SFMLrpg/lib/build/MinSizeRel/libprpg.a


PostBuild.prpg.RelWithDebInfo:
/Users/adodman/mcdreamer/SFMLrpg/lib/build/RelWithDebInfo/libprpg.a:
	/bin/rm -f /Users/adodman/mcdreamer/SFMLrpg/lib/build/RelWithDebInfo/libprpg.a




# For each target create a dummy ruleso the target does not have to exist
