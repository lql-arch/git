static int diff_compaction_heuristic; /* experimental */
		DIFF_OPT_SET(options, SUBMODULE_LOG);
		DIFF_OPT_CLR(options, SUBMODULE_LOG);
	if (!strcmp(var, "diff.compactionheuristic")) {
		diff_compaction_heuristic = git_config_bool(var, value);
		return 0;
	}
	if (git_color_config(var, value, cb) < 0)
		return -1;
	char hex[GIT_SHA1_HEXSZ + 1];
 *   1. collect a the minus/plus lines of a diff hunk, divided into
		free(ecbdata->diff_words);
		ecbdata->diff_words = NULL;
		width = term_columns() - options->output_prefix_length;
	qsort(dir.files, dir.nr, sizeof(dir.files[0]), dirstat_compare);
			damage = (damage + 63) / 64;
	qsort(dir.files, dir.nr, sizeof(dir.files[0]), dirstat_compare);
	if (DIFF_OPT_TST(o, SUBMODULE_LOG) &&
			(!one->mode || S_ISGITLINK(one->mode)) &&
			(!two->mode || S_ISGITLINK(two->mode))) {
				one->oid.hash, two->oid.hash,
	diff_set_mnemonic_prefix(o, "a/", "b/");
	if (DIFF_OPT_TST(o, REVERSE_DIFF)) {
		a_prefix = o->b_prefix;
		b_prefix = o->a_prefix;
	} else {
		a_prefix = o->a_prefix;
		b_prefix = o->b_prefix;
	}

void fill_filespec(struct diff_filespec *spec, const unsigned char *sha1,
		   int sha1_valid, unsigned short mode)
		hashcpy(spec->oid.hash, sha1);
		spec->oid_valid = sha1_valid;
static int reuse_worktree_file(const char *name, const unsigned char *sha1, int want_file)
	if (!FAST_WORKING_DIRECTORY && !want_file && has_sha1_pack(sha1))
	if (!want_file && would_convert_to_git(name))
	if (hashcmp(sha1, ce->sha1) || !S_ISREG(ce->ce_mode))
	    reuse_worktree_file(s->path, s->oid.hash, 0)) {
		if (size_only)
		if (convert_to_git(s->path, s->data, s->size, &buf, crlf_warn)) {
	free(s->cnt_data);
	s->cnt_data = NULL;
	     reuse_worktree_file(name, one->oid.hash, 1))) {
				sha1_to_hex_r(temp->hex, null_sha1);
				sha1_to_hex_r(temp->hex, one->oid.hash);
			 * !(one->sha1_valid), as long as
		strbuf_addf(msg, "%s%sindex %s..", line_prefix, set,
			    find_unique_abbrev(one->oid.hash, abbrev));
		strbuf_add_unique_abbrev(msg, two->oid.hash, abbrev);
static void diff_fill_sha1_info(struct diff_filespec *one)
	diff_fill_sha1_info(one);
	diff_fill_sha1_info(two);
	diff_fill_sha1_info(p->one);
	diff_fill_sha1_info(p->two);
	diff_fill_sha1_info(p->one);
	diff_fill_sha1_info(p->two);
	options->ws_error_highlight = WSEH_NEW;
	if (diff_compaction_heuristic)
		DIFF_XDL_SET(options, COMPACTION_HEURISTIC);
		die("--name-only, --name-status, --check and -s are mutually exclusive");
	if (options->abbrev <= 0 || 40 < options->abbrev)
				die("Option '--stat-width' requires a value");
				die("Option '--stat-name-width' requires a value");
				die("Option '--stat-graph-width' requires a value");
				die("Option '--stat-count' requires a value");
static int parse_one_token(const char **arg, const char *token)
	const char *rest;
	if (skip_prefix(*arg, token, &rest) && (!*rest || *rest == ',')) {
		*arg = rest;
		return 1;
	}
	return 0;
}
static int parse_ws_error_highlight(struct diff_options *opt, const char *arg)
{
	const char *orig_arg = arg;
	unsigned val = 0;
	while (*arg) {
		if (parse_one_token(&arg, "none"))
			val = 0;
		else if (parse_one_token(&arg, "default"))
			val = WSEH_NEW;
		else if (parse_one_token(&arg, "all"))
			val = WSEH_NEW | WSEH_OLD | WSEH_CONTEXT;
		else if (parse_one_token(&arg, "new"))
			val |= WSEH_NEW;
		else if (parse_one_token(&arg, "old"))
			val |= WSEH_OLD;
		else if (parse_one_token(&arg, "context"))
			val |= WSEH_CONTEXT;
		else {
			error("unknown value after ws-error-highlight=%.*s",
			      (int)(arg - orig_arg), orig_arg);
			return 0;
		}
		if (*arg)
			arg++;
	else if (!strcmp(arg, "--compaction-heuristic"))
		DIFF_XDL_SET(options, COMPACTION_HEURISTIC);
	else if (!strcmp(arg, "--no-compaction-heuristic"))
		DIFF_XDL_CLR(options, COMPACTION_HEURISTIC);
		DIFF_OPT_SET(options, SUBMODULE_LOG);
		return parse_ws_error_highlight(options, arg);
		const char *path = prefix_filename(prefix, strlen(prefix), optarg);
		options->orderfile = xstrdup(path);
		const char *path = prefix_filename(prefix, strlen(prefix), optarg);
		options->file = fopen(path, "w");
		if (!options->file)
			die_errno("Could not open '%s'", path);
/*
 * This is different from find_unique_abbrev() in that
 * it stuffs the result with dots for alignment.
 */
const char *diff_unique_abbrev(const unsigned char *sha1, int len)
	if (len == 40)
		return sha1_to_hex(sha1);
	abbrev = find_unique_abbrev(sha1, len);
	if (abblen < 37) {
		static char hex[41];
	return sha1_to_hex(sha1);
			diff_unique_abbrev(p->one->oid.hash, opt->abbrev));
			diff_unique_abbrev(p->two->oid.hash, opt->abbrev));
static int diff_get_patch_id(struct diff_options *options, unsigned char *sha1, int diff_header_only)
	char buffer[PATH_MAX * 4 + 20];
		diff_fill_sha1_info(p->one);
		diff_fill_sha1_info(p->two);
		if (p->one->mode == 0)
			len1 = snprintf(buffer, sizeof(buffer),
					"diff--gita/%.*sb/%.*s"
					"newfilemode%06o"
					"---/dev/null"
					"+++b/%.*s",
					len1, p->one->path,
					len2, p->two->path,
					p->two->mode,
					len2, p->two->path);
		else if (p->two->mode == 0)
			len1 = snprintf(buffer, sizeof(buffer),
					"diff--gita/%.*sb/%.*s"
					"deletedfilemode%06o"
					"---a/%.*s"
					"+++/dev/null",
					len1, p->one->path,
					len2, p->two->path,
					p->one->mode,
					len1, p->one->path);
		else
			len1 = snprintf(buffer, sizeof(buffer),
					"diff--gita/%.*sb/%.*s"
					"---a/%.*s"
					"+++b/%.*s",
					len1, p->one->path,
					len2, p->two->path,
					len1, p->one->path,
					len2, p->two->path);
		git_SHA1_Update(&ctx, buffer, len1);
					40);
					40);
	git_SHA1_Final(sha1, &ctx);
int diff_flush_patch_id(struct diff_options *options, unsigned char *sha1, int diff_header_only)
	int result = diff_get_patch_id(options, sha1, diff_header_only);
"inexact rename detection was skipped due to too many files.";
"only found copies from modified paths due to too many files.";
"you may want to set your %s variable to at least "
"%d and retry the command.";
		warning(degrade_cc_to_c_warning);
		warning(rename_limit_warning);
		warning(rename_limit_advice, varname, needed);
		options->file = fopen("/dev/null", "w");
		if (!options->file)
			die_errno("Could not open /dev/null");
	qsort(q->queue, q->nr, sizeof(q->queue[0]), diffnamecmp);
		    const unsigned char *sha1,
		    int sha1_valid,
		fill_filespec(one, sha1, sha1_valid, mode);
		fill_filespec(two, sha1, sha1_valid, mode);
		 const unsigned char *old_sha1,
		 const unsigned char *new_sha1,
		 int old_sha1_valid, int new_sha1_valid,
		unsigned tmp;
		const unsigned char *tmp_c;
		tmp = old_mode; old_mode = new_mode; new_mode = tmp;
		tmp_c = old_sha1; old_sha1 = new_sha1; new_sha1 = tmp_c;
		tmp = old_sha1_valid; old_sha1_valid = new_sha1_valid;
			new_sha1_valid = tmp;
		tmp = old_dirty_submodule; old_dirty_submodule = new_dirty_submodule;
			new_dirty_submodule = tmp;
	fill_filespec(one, old_sha1, old_sha1_valid, old_mode);
	fill_filespec(two, new_sha1, new_sha1_valid, new_mode);
					  df->oid.hash,
		notes_cache_put(driver->textconv_cache, df->oid.hash, *outbuf,